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

#include "component.h"

#include <stdlib.h>

#include "log.h"

// --- Public Function Definitions ---
Component *component_health_create(int current_hp, int max_hp)
{
    Component *component = malloc(sizeof(*component));
    if (!component)
    {
        log_perror("Component allocation failure");
        log_fatal("%s: Fatal error", __func__);
    }

    component->type = COMPONENT_TYPE_HEALTH;
    component->params.health.current_hp = current_hp;
    component->params.health.max_hp = max_hp;

    return component;
}
Component *component_combat_create(int attack_power)
{
    Component *component = malloc(sizeof(*component));
    if (!component)
    {
        log_perror("Component allocation failure");
        log_fatal("%s: Fatal error", __func__);
    }

    component->type = COMPONENT_TYPE_COMBAT;
    component->params.combat.attack_power = attack_power;

    return component;
}
Component *component_ai_create(void)
{
    Component *component = malloc(sizeof(*component));
    if (!component)
    {
        log_perror("Component allocation failure");
        log_fatal("%s: Fatal error", __func__);
    }

    component->type = COMPONENT_TYPE_AI;
    component->params.ai.placeholder = 0;

    return component;
}

void component_free(Component *component)
{
    free(component);
}

const char *component_get_name_from_type(ComponentType type)
{
    switch (type)
    {
    case COMPONENT_TYPE_NONE:
    {
        return "NONE";
    }

    case COMPONENT_TYPE_HEALTH:
    {
        return "HEALTH";
    }

    case COMPONENT_TYPE_COMBAT:
    {
        return "COMBAT";
    }

    case COMPONENT_TYPE_AI:
    {
        return "AI";
    }

    default:
    {
        return "UNKNOWN";
    }
    }
}
