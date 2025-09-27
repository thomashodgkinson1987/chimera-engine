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

#ifndef COMMAND_SYSTEM_H
#define COMMAND_SYSTEM_H

#include "process_result.h"

// --- Forward Declarations ---
typedef struct command Command;
typedef struct world World;
typedef struct command_system CommandSystem;

// --- Public Function Prototypes ---
CommandSystem *command_system_create(void);
void command_system_free(CommandSystem *command_system);

void command_system_add_command(
    CommandSystem *command_system,
    const Command *command);

ProcessResult command_system_process_queue(
    CommandSystem *command_system,
    World *world);

#endif // COMMAND_SYSTEM_H
