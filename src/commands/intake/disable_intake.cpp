#include "commands/intake/disable_intake.hpp"
#include "subsystems/intake.hpp"

DisableIntake::DisableIntake(Intake *intake)
    : m_completed(false), m_intake(intake) {
  add_requirements({intake});
}

void DisableIntake::initialize() {
  m_intake->disable();
  m_completed = true;
}

bool DisableIntake::is_finished() { return m_completed; }

void DisableIntake::end(bool interrupted) { m_completed = false; }