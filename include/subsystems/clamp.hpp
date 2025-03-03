#pragma once

#include "pros/motors.hpp"
#include "uvlib/subsystem.hpp"
class Clamp : public uvl::Subsystem {
public:
  Clamp();

  void set_voltage(int voltage);

private:
  pros::Motor m_clamp_motor;
};