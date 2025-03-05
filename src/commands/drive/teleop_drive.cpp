#include "commands/drive/teleop_drive.hpp"
#include "uvlib/input/controller.hpp"

TeleopDrive::TeleopDrive(Drivetrain *drivetrain, uvl::Controller *controller)
    : m_chassis(drivetrain->get_chassis()),
      m_left_joystick(controller->left_joystick()),
      m_right_joystick(controller->right_joystick()) {
  add_requirements({drivetrain});
}

void TeleopDrive::execute() {
  int left_y = m_right_joystick.get_y();
  int right_x = m_left_joystick.get_x();

  m_chassis->curvature(left_y, right_x);
}

bool TeleopDrive::is_finished() { return false; }

void TeleopDrive::end(bool interrupted) { m_chassis->curvature(0, 0); }