#pragma once

#include "subsystems/clamp.hpp"
#include "uvlib/commands/command.hpp"
#include "uvlib/commands/command_helper.hpp"
class ClampRelease : public uvl::CommandHelper<uvl::Command, ClampRelease> {
public:
  ClampRelease(Clamp *clamp);

protected:
  void initialize() override;

  bool is_finished() override;

  void end(bool interrupted) override;

private:
  Clamp *m_clamp;

  int m_end_time;
};