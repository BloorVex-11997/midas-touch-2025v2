#include "subsystems/intake.hpp"

#include "constants/intake_constants.hpp"

Intake::Intake()
    : m_intake_motor(INTAKE_PORT), m_elevator_motor(ELEVATOR_PORT) {}

void Intake::set_voltage(int intake_voltage, int elevator_voltage) {
  m_intake_motor.move(-intake_voltage);
  m_elevator_motor.move(-elevator_voltage);
}

void Intake::enable() { set_voltage(INTAKE_VOLTAGE, ELEVATOR_VOLTAGE); }

void Intake::reverse() { set_voltage(-INTAKE_VOLTAGE, -ELEVATOR_VOLTAGE); }

void Intake::disable() { set_voltage(0, 0); }