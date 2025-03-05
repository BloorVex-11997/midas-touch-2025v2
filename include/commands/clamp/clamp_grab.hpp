#pragma once

#include "subsystems/clamp.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class ClampGrab : public uvl::CommandHelper<uvl::Command, ClampGrab> {
public:
  ClampGrab(Clamp *clamp);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  Clamp *m_clamp;
};