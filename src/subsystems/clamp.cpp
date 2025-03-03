#include "subsystems/clamp.hpp"
#include "constants/clamp_constants.hpp"

Clamp::Clamp() : m_clamp_motor(CLAMP_PORT) {}

void Clamp::set_voltage(int voltage) { m_clamp_motor.move_voltage(voltage); }