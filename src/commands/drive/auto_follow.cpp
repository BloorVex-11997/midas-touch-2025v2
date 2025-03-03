#include "commands/drive/auto_follow.hpp"
#include "subsystems/drivetrain.hpp"

AutoFollow::AutoFollow(Drivetrain *drivetrain, const asset &path,
                       float lookahead, int timeout, bool forwards)
    : m_chassis(drivetrain->get_chassis()), m_path(path),
      m_lookahead(lookahead), m_timeout(timeout), m_forwards(forwards) {
  add_requirements({drivetrain});
}

void AutoFollow::initialize() {
  m_chassis->follow(m_path, m_lookahead, m_timeout, m_forwards);
}

bool AutoFollow::is_finished() { return m_chassis->isInMotion(); }

void AutoFollow::end(bool interrupted) { m_chassis->cancelMotion(); }