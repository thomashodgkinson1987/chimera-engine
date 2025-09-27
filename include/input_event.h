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

#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

// --- Type Definitions ---
typedef enum input_event_type
{
    INPUT_EVENT_TYPE_NONE,

    INPUT_EVENT_TYPE_ACTOR_MOVE_NORTH,
    INPUT_EVENT_TYPE_ACTOR_MOVE_SOUTH,
    INPUT_EVENT_TYPE_ACTOR_MOVE_EAST,
    INPUT_EVENT_TYPE_ACTOR_MOVE_WEST,

    INPUT_EVENT_TYPE_ACTOR_WAIT,

    INPUT_EVENT_TYPE_QUIT,

    INPUT_EVENT_TYPE_COUNT
} InputEventType;

typedef struct input_event
{
    InputEventType type;
} InputEvent;

#endif // INPUT_EVENT_H
