#pragma once

#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/abstract_motor.hpp"

/* Ports */
const int MOTOR_PORT_LEFT_FRONT = -16;
const int MOTOR_PORT_LEFT_BACK = -19;
const int MOTOR_PORT_RIGHT_FRONT = 15;
const int MOTOR_PORT_RIGHT_BACK = 20;

const int IMU_PORT = 17;

/* Configuration */
const float TRACK_WIDTH = 15.25;
const float RPM = 600 * 36.0 / 84;
const float HORIZONTAL_DRIFT = 2.0;

const pros::MotorGearset GEARSET = pros::MotorGearset::blue;
const float WHEEL_DIAMETER = lemlib::Omniwheel::NEW_4;
const float GEAR_RATIO = 36.0 / 84;