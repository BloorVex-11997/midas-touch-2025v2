#pragma once

#include "subsystems/clamp.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
#include "uvlib/subsystem.hpp"

enum struct ClampState { CLAMPED, UNCLAMPED };

class SetClampState : public uvl::CommandHelper<uvl::Command, SetClampState> {
public:
  SetClampState(Clamp *clamp, ClampState state);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  Clamp *m_clamp;

  ClampState m_state;
  int m_end_time;
};
