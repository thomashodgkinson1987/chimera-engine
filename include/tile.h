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

#ifndef TILE_H
#define TILE_H

#include "colour.h"

// --- Type Definitions ---
typedef enum tile_type
{
    TILE_TYPE_FLOOR,
    TILE_TYPE_WALL
} TileType;

typedef struct tile
{
    TileType type;
    Colour fg_colour;
    Colour bg_colour;
} Tile;

#endif // TILE_H
