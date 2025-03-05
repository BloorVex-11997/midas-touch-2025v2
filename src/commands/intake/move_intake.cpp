#include "commands/intake/move_intake.hpp"
#include "subsystems/intake.hpp"

MoveIntake::MoveIntake(Intake *intake, bool reverse)
    : m_completed(false), m_intake(intake), m_reverse(reverse) {
  add_requirements({intake});
}

void MoveIntake::initialize() {
  if (!m_reverse) {
    m_intake->enable();
  } else {
    m_intake->disable();
  }

  m_completed = true;
}

bool MoveIntake::is_finished() { return m_completed; }

void MoveIntake::end(bool interrupted) { m_completed = false; }