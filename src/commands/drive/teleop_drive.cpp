#include "commands/drive/teleop_drive.hpp"

TeleopDrive::TeleopDrive(Drivetrain *drivetrain)
    : m_chassis(drivetrain->get_chassis()) {
  add_requirements({drivetrain});
}

void TeleopDrive::execute() {
  int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  // move the robot
  chassis.curvature(leftY, rightX);
}
