#include "commands/drive/face_heading.hpp"

#include "lemlib/chassis/chassis.hpp"
#include "subsystems/drivetrain.hpp"

FaceHeading::FaceHeading(Drivetrain *drivetrain, float theta,
                         lemlib::TurnToHeadingParams params)
    : m_chassis(drivetrain->get_chassis()), m_theta(theta), m_params(params) {
  add_requirements({drivetrain});
}

void FaceHeading::initialize() {
  m_chassis->turnToHeading(m_theta, 100000000, m_params);
}

bool FaceHeading::is_finished() { return !m_chassis->isInMotion(); }

void FaceHeading::end(bool interrupted) { m_chassis->cancelAllMotions(); }