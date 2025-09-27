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

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

// --- Forward Declarations ---
typedef struct command Command;

typedef struct renderer Renderer;
typedef struct world World;
typedef struct command_system CommandSystem;
typedef struct input_system InputSystem;

typedef struct game Game;

// --- Public Function Prototypes ---
Game *game_create(
    Renderer *renderer,
    World *world,
    CommandSystem *command_system,
    InputSystem *input_system);
void game_init(Game *game);
void game_run(Game *game);
void game_free(Game *game);

bool game_add_command(Game *game, const Command *command);

#endif // GAME_H
