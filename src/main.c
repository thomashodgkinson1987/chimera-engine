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

#include "game.h"

#include "command_system.h"
#include "input_system.h"
#include "renderer.h"
#include "world.h"

int main(void)
{
    Renderer *renderer = renderer_create(512, 512, "gridtest");
    World *world = world_create(16, 16);
    CommandSystem *command_system = command_system_create();
    InputSystem *input_system = input_system_create();

    Game *game = game_create(renderer, world, command_system, input_system);
    game_init(game);
    game_run(game);
    game_free(game);

    return 0;
}
