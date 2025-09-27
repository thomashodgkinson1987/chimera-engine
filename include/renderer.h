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

#ifndef RENDERER_H
#define RENDERER_H

#include <stdbool.h>

#include "colour.h"

// --- Forward Declarations ---
typedef struct renderer Renderer;
typedef struct world World;

// --- Public Function Prototypes ---
Renderer *renderer_create(
    int screen_width,
    int screen_height,
    const char *screen_title);
void renderer_free(Renderer *renderer);

void renderer_set_dirty(Renderer *renderer);

void renderer_begin_frame(Renderer *renderer, const World *world);
void renderer_end_frame(Renderer *renderer);

void renderer_draw_glyph(
    const Renderer *renderer,
    int grid_x,
    int grid_y,
    char glyph,
    Colour fg_colour,
    Colour bg_colour);

void renderer_draw_text(
    int pixel_x,
    int pixel_y,
    const char *text,
    Colour colour,
    int size);

#endif // RENDERER_H
