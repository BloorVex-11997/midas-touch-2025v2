#include "subsystems/drivetrain.hpp"
#include "constants/drive_constants.hpp"
#include "lemlib/chassis/chassis.hpp"

Drivetrain::Drivetrain()
    : m_left_motors({MOTOR_PORT_LEFT_BACK, MOTOR_PORT_LEFT_FRONT}),
      m_right_motors({MOTOR_PORT_RIGHT_BACK, MOTOR_PORT_RIGHT_FRONT}),
      m_imu(IMU_PORT),
      m_drivetrain(&m_left_motors, &m_right_motors, TRACK_WIDTH, WHEEL_DIAMETER,
                   RPM, HORIZONTAL_DRIFT),
      m_sensors(nullptr, nullptr, nullptr, nullptr, &m_imu),
      m_lateral_pid(10,  // proportional gain (kP)
                    0,   // integral gain (kI)
                    3,   // derivative gain (kD)
                    3,   // anti windup
                    1,   // small error range, in inches
                    100, // small error range timeout, in milliseconds
                    3,   // large error range, in inches
                    500, // large error range timeout, in milliseconds
                    20   // maximum acceleration (slew)
                    ),
      m_angular_pid(2,   // proportional gain (kP)
                    0,   // integral gain (kI)
                    10,  // derivative gain (kD)
                    3,   // anti windup
                    1,   // small error range, in degrees
                    100, // small error range timeout, in milliseconds
                    3,   // large error range, in degrees
                    500, // large error range timeout, in milliseconds
                    0    // maximum acceleration (slew)
                    ),
      m_throttle_curve(
          3,    // joystick deadband out of 127
          10,   // minimum output where drivetrain will move out of 127
          1.019 // expo curve gain
          ),
      m_steer_curve(3,  // joystick deadband out of 127
                    10, // minimum output where drivetrain will move out of 127
                    1.019 // expo curve gain
                    ),
      m_chassis(m_drivetrain, m_lateral_pid, m_angular_pid, m_sensors,
                &m_throttle_curve, &m_steer_curve) {}

void Drivetrain::initialize() {
  m_chassis.calibrate(true);
  m_chassis.setPose(0, 0, 0);
}

lemlib::Chassis *Drivetrain::get_chassis() { return &m_chassis; }