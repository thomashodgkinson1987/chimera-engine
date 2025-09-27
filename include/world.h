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

#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>

#include "command.h"
#include "tile.h"

// --- Forward Declarations ---
typedef struct world World;

// --- Public Function Prototypes ---
World *world_create(int width, int height);
void world_free(World *world);

int world_get_width(const World *world);
int world_get_height(const World *world);

void world_add_actor(World *world, Actor *actor);
void world_remove_actor(World *world, Actor *actor);
void world_update_actors(World *world);

Command world_actor_attack_actor(
    World *world,
    Actor *attacker,
    Actor *defender);

const Actor *world_get_actor_at(const World *world, int x, int y);
Actor *world_get_actor_at_mut(World *world, int x, int y);

const Tile *world_get_tile_at(const World *world, int x, int y);
Tile *world_get_tile_at_mut(World *world, int x, int y);

bool world_is_tile_walkable(const World *world, int x, int y);

#endif // WORLD_H
