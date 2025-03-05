#pragma once

#include "subsystems/intake.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class MoveIntake : public uvl::CommandHelper<uvl::Command, MoveIntake> {
public:
  MoveIntake(Intake *intake, bool reverse = false);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  bool m_reverse;
  bool m_completed;

  Intake *m_intake;
};