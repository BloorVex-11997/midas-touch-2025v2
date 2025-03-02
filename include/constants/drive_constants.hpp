#pragma once

#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/abstract_motor.hpp"

/* Ports */
const int MOTOR_PORT_LEFT_FRONT = 0;
const int MOTOR_PORT_LEFT_BACK = 2;
const int MOTOR_PORT_RIGHT_FRONT = 1;
const int MOTOR_PORT_RIGHT_BACK = 3;

const int IMU_PORT = 0;

/* Configuration */
const float TRACK_WIDTH = 0.0;
const float RPM = 0.0;
const float HORIZONTAL_DRIFT = 0.0;

const pros::MotorGearset GEARSET = pros::MotorGearset::blue;
const float WHEEL_DIAMETER = lemlib::Omniwheel::NEW_2;
const float DISTANCE = 0;
const float GEAR_RATIO = 1;