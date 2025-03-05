#include "commands/clamp/clamp_release.hpp"
#include "constants/clamp_constants.hpp"
#include "subsystems/clamp.hpp"

ClampRelease::ClampRelease(Clamp *clamp) : m_clamp(clamp) {
  add_requirements({clamp});
}

void ClampRelease::initialize() { m_clamp->set_voltage(-CLAMP_VOLTAGE * 0.5); }

bool ClampRelease::is_finished() { return false; }

void ClampRelease::end(bool interrupted) { m_clamp->set_voltage(0); }