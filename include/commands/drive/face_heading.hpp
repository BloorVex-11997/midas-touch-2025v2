#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "subsystems/drivetrain.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class FaceHeading : public uvl::CommandHelper<uvl::Command, FaceHeading> {
public:
  FaceHeading(Drivetrain *drivetrain, float theta,
              lemlib::TurnToHeadingParams params = {});

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  lemlib::Chassis *m_chassis;

  float m_theta;
  lemlib::TurnToHeadingParams m_params;
};