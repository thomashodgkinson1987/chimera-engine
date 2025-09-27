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

#ifndef GAME_STATE_H
#define GAME_STATE_H

// --- Type Definitions ---
typedef enum game_state
{
    GAME_STATE_WAITING_FOR_INPUT,
    GAME_STATE_PLAYER_TURN,
    GAME_STATE_ENEMY_TURN,
    GAME_STATE_QUIT
} GameState;

#endif // GAME_STATE_H
