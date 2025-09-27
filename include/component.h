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

#ifndef COMPONENT_H
#define COMPONENT_H

// --- Type Definitions ---
typedef enum component_type
{
    COMPONENT_TYPE_NONE,
    COMPONENT_TYPE_HEALTH,
    COMPONENT_TYPE_COMBAT,
    COMPONENT_TYPE_AI,
    COMPONENT_TYPE_COUNT
} ComponentType;

typedef struct component_params_health
{
    int current_hp;
    int max_hp;
} ComponentParamsHealth;

typedef struct component_params_combat
{
    int attack_power;
} ComponentParamsCombat;

typedef struct component_params_ai
{
    int placeholder;
} ComponentParamsAi;

typedef struct component
{
    ComponentType type;
    union
    {
        ComponentParamsHealth health;
        ComponentParamsCombat combat;
        ComponentParamsAi ai;
    } params;
} Component;

// --- Public Function Prototypes ---
Component *component_health_create(int current_hp, int max_hp);
Component *component_combat_create(int attack_power);
Component *component_ai_create(void);

void component_free(Component *component);

const char *component_get_name_from_type(ComponentType type);

#endif // COMPONENT_H
