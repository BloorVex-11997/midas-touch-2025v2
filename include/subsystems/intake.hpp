#pragma once

#include "uvlib/subsystem.hpp"
class Intake : public uvl::Subsystem {
public:
  Intake();

  void set_voltage(int intake_voltage, int elevator_voltage);

  void enable();

  void disable();

private:
  int m_intake_voltage = 0;
  int m_elevator_voltage = 0;

  pros::Motor m_intake_motor;
  pros::Motor m_elevator_motor;
};