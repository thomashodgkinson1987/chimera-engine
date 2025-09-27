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

#ifndef ACTOR_HASH_MAP_H
#define ACTOR_HASH_MAP_H

#include <stddef.h> // for size_t
#include <stdint.h> // for uint64_t

// --- Forward Declarations ---
typedef struct actor Actor;
typedef struct actor_hash_map ActorHashMap;

// --- Public Function Prototypes ---
ActorHashMap *actor_hash_map_create(size_t initial_capacity);
void actor_hash_map_free(ActorHashMap *hash_map);

size_t actor_hash_map_get_count(const ActorHashMap *hash_map);
size_t actor_hash_map_get_capacity(const ActorHashMap *hash_map);

void actor_hash_map_add(ActorHashMap *hash_map, const Actor *actor);
void actor_hash_map_remove(ActorHashMap *hash_map, uint64_t id);

const Actor *actor_hash_map_get(const ActorHashMap *hash_map, uint64_t id);
Actor *actor_hash_map_get_mut(ActorHashMap *hash_map, uint64_t id);

#endif // ACTOR_HASH_MAP_H
