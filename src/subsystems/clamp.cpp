#include "subsystems/clamp.hpp"
#include "constants/clamp_constants.hpp"
#include "pros/motors.h"

Clamp::Clamp() : m_clamp_motor(CLAMP_PORT) {
  m_clamp_motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Clamp::set_voltage(int voltage) { m_clamp_motor.move(-voltage); }