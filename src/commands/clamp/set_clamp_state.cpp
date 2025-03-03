#include "commands/clamp/set_clamp_state.hpp"
#include "constants/clamp_constants.hpp"
#include "pros/rtos.hpp"
#include "subsystems/clamp.hpp"

SetClampState::SetClampState(Clamp *clamp, ClampState state)
    : m_clamp(clamp), m_state(state) {
  add_requirements({clamp});
}

void SetClampState::initialize() {
  m_end_time = pros::millis() + CLAMP_DURATION;

  if (m_state == ClampState::CLAMPED) {
    m_clamp->set_voltage(CLAMP_VOLTAGE);
  } else {
    m_clamp->set_voltage(-CLAMP_VOLTAGE);
  }
}

bool SetClampState::is_finished() { return pros::millis() >= m_end_time; }

void SetClampState::end(bool interrupted) { m_clamp->set_voltage(0); }