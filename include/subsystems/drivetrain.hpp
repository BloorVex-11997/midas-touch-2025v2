#pragma once

#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "uvlib/subsystem.hpp"

class Drivetrain : public uvl::Subsystem {
public:
  Drivetrain();

  void initialize() override;

  lemlib::Chassis *get_chassis();

private:
  pros::MotorGroup m_left_motors;
  pros::MotorGroup m_right_motors;

  pros::Imu m_imu;

  lemlib::ControllerSettings m_lateral_pid;
  lemlib::ControllerSettings m_angular_pid;

  lemlib::ExpoDriveCurve m_throttle_curve;
  lemlib::ExpoDriveCurve m_steer_curve;

  lemlib::OdomSensors m_sensors;
  lemlib::Drivetrain m_drivetrain;
  lemlib::Chassis m_chassis;
};