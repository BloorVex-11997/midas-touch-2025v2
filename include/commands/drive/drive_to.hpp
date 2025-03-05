#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "subsystems/drivetrain.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class DriveTo : public uvl::CommandHelper<uvl::Command, DriveTo> {
public:
  DriveTo(Drivetrain *drivetrain, float x, float y,
          lemlib::MoveToPointParams params = {});

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  lemlib::Chassis *m_chassis;

  float m_x;
  float m_y;
  lemlib::MoveToPointParams m_params;
};