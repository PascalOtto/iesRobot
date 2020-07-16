#pragma once

#include <stdbool.h>

typedef enum {STOP, FORWARD, BACKWARD} motorcontrol_direction;

void motorcontrol_init(void);
void motorcontrol_enable(bool enable);
void motorcontrol_stop(void);
void motorcontrol_drive(motorcontrol_direction left, motorcontrol_direction right);
