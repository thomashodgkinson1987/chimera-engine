/*
 * Chimera Engine
 * Copyright (C) 2025  Thomas George Hodgkinson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include <stdbool.h>

#include "input_event.h"

// --- Forward Declarations ---
typedef struct input_system InputSystem;

// --- Public Function Prototypes ---
InputSystem *input_system_create(void);
void input_system_free(InputSystem *input_system);

void input_system_poll_input(InputSystem *input_system);

bool input_system_has_event(const InputSystem *input_system);
InputEvent input_system_next_event(InputSystem *input_system);

#endif // INPUT_SYSTEM_H
