#pragma once

#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "subsystems/drivetrain.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"

class AutoFollow : public uvl::CommandHelper<uvl::Command, AutoFollow> {
public:
  AutoFollow(Drivetrain *drivetrain, const asset &path, float lookahead,
             int timeout, bool forwards = true);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  lemlib::Chassis *m_chassis;
  const asset &m_path;
  float m_lookahead;
  int m_timeout;
  bool m_forwards;
};