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

#ifndef LOG_H
#define LOG_H

// --- Macro Definitions ---
// Use the C11 standard noreturn if available
#if __STDC_VERSION__ >= 201112L
#include <stdnoreturn.h>
#define ATTR_NORETURN noreturn
// Fallback to GCC/Clang attribute
#elif defined(__GNUC__) || defined(__clang__)
#define ATTR_NORETURN __attribute__((noreturn))
// Otherwise, define it as empty
#else
#define ATTR_NORETURN
#endif

// --- Type Definitions ---
typedef enum log_level
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} LogLevel;

// --- Public Function Prototypes ---
void log_message(LogLevel level, const char *format, ...);
void log_perror(const char *format, ...);
ATTR_NORETURN void log_fatal(const char *format, ...);

#endif // LOG_H
