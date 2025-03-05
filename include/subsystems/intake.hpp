#pragma once

#include "uvlib/subsystem.hpp"
class Intake : public uvl::Subsystem {
public:
  Intake();

  void set_voltage(int intake_voltage, int elevator_voltage);

  void enable();

  void reverse();

  void disable();

private:
  pros::Motor m_intake_motor;
  pros::Motor m_elevator_motor;
};