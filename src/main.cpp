#include "main.h"
#include "commands/clamp/clamp_grab.hpp"
#include "commands/clamp/clamp_release.hpp"
#include "commands/clamp/set_clamp_state.hpp"
#include "commands/drive/auto_follow.hpp"
#include "commands/drive/teleop_drive.hpp"
#include "commands/intake/disable_intake.hpp"
#include "commands/intake/move_intake.hpp"
#include "constants/clamp_constants.hpp"
#include "pros/misc.h"
#include "subsystems/clamp.hpp"
#include "subsystems/drivetrain.hpp"
#include "subsystems/intake.hpp"
#include "uvlib/commands/advanced_commands/instant_command.hpp"
#include "uvlib/enums.hpp"
#include "uvlib/input/controller.hpp"
#include "uvlib/input/trigger.hpp"
#include "uvlib/scheduler.hpp"

#define MINT 100000000

ASSET(example_txt);

uvl::Controller *controller;
Drivetrain *drivetrain;
Intake *intake;
Clamp *clamp;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();

  controller = new uvl::Controller(pros::E_CONTROLLER_MASTER);
  drivetrain = new Drivetrain();
  intake = new Intake();
  clamp = new Clamp();

  drivetrain->set_default_command(TeleopDrive(drivetrain, controller).to_ptr());

  uvl::Scheduler::get_instance().initialize();

  // autonomous();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  lemlib::Chassis *chassis = drivetrain->get_chassis();
  clamp->set_voltage(-CLAMP_VOLTAGE * 0.5);

  chassis->moveToPoint(0, -30, MINT, {.forwards = false}, false);
  pros::delay(200);

  clamp->set_voltage(CLAMP_VOLTAGE);
  pros::delay(200);

  intake->enable();
  pros::delay(1500);

  intake->reverse();
  pros::delay(500);

  intake->disable();
  chassis->turnToHeading(90, 1000, {}, false);
  pros::delay(200);

  intake->enable();
  chassis->moveToPoint(25, -30, MINT, {}, false);
  pros::delay(1000);

  intake->disable();

  // uvl::Scheduler::get_instance().mainloop();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  controller->get_trigger(uvl::TriggerButton::kR2)
      .on_true(MoveIntake(intake, false).to_ptr());

  controller->get_trigger(uvl::TriggerButton::kL2)
      .on_true(DisableIntake(intake).to_ptr());

  controller->get_trigger(uvl::TriggerButton::kA)
      .on_true(MoveIntake(intake, true).to_ptr());

  controller->get_trigger(uvl::TriggerButton::kR1)
      .on_true(ClampGrab(clamp).to_ptr());

  controller->get_trigger(uvl::TriggerButton::kL1)
      .on_true(ClampRelease(clamp).to_ptr());

  uvl::Scheduler::get_instance().mainloop();
}