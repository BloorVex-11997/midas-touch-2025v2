#pragma once

#include "subsystems/intake.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class DisableIntake : public uvl::CommandHelper<uvl::Command, DisableIntake> {
public:
  DisableIntake(Intake *intake);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  bool m_completed;

  Intake *m_intake;
};