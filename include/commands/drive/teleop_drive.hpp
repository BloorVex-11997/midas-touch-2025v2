#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "subsystems/drivetrain.hpp"
#include "uvlib/command_api.hpp"
#include "uvlib/input_api.hpp"

class TeleopDrive : public uvl::CommandHelper<uvl::Command, TeleopDrive> {
public:
  TeleopDrive(Drivetrain *drivetrain, uvl::Controller *controller);

  void execute() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  lemlib::Chassis *m_chassis;
};