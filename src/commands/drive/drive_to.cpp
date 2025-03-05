#include "commands/drive/drive_to.hpp"

DriveTo::DriveTo(Drivetrain *drivetrain, float x, float y,
                 lemlib::MoveToPointParams params)
    : m_chassis(drivetrain->get_chassis()), m_x(x), m_y(y), m_params(params) {
  add_requirements({drivetrain});
}

void DriveTo::initialize() {
  m_chassis->moveToPoint(m_x, m_y, 100000000, m_params);
}

bool DriveTo::is_finished() { return !m_chassis->isInMotion(); }

void DriveTo::end(bool interrupted) { m_chassis->cancelAllMotions(); }