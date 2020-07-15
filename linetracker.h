#pragma once

#include <stdbool.h>

typedef enum {RIGHTTRACKER, MIDTRACKER, LEFTTRACKER} linetracker_Tracker;

void linetracker_init(void);
int linetracker_measure_wait(linetracker_Tracker tracker);
bool linetracker_is_triggered(linetracker_Tracker tracker);
