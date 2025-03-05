#include "commands/clamp/clamp_release.hpp"
#include "constants/clamp_constants.hpp"
#include "subsystems/clamp.hpp"

ClampRelease::ClampRelease(Clamp *clamp) : m_clamp(clamp) {
  add_requirements({clamp});
}

void ClampRelease::initialize() {
  m_end_time = pros::millis() + CLAMP_DURATION;
  m_clamp->set_voltage(-CLAMP_VOLTAGE);
}

bool ClampRelease::is_finished() { return pros::millis() >= m_end_time; }

void ClampRelease::end(bool interrupted) { m_clamp->set_voltage(0); }