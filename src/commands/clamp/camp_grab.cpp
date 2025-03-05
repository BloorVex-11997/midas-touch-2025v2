#include "commands/clamp/clamp_grab.hpp"
#include "constants/clamp_constants.hpp"
#include "subsystems/clamp.hpp"

ClampGrab::ClampGrab(Clamp *clamp) : m_clamp(clamp) {
  add_requirements({clamp});
}

void ClampGrab::initialize() { m_clamp->set_voltage(CLAMP_VOLTAGE); }

bool ClampGrab::is_finished() { return false; }

void ClampGrab::end(bool interrupted) { m_clamp->set_voltage(0); }