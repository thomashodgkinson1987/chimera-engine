cmake_minimum_required(VERSION 3.15)

# --- Project and C Standard Setup ---
project(ChimeraEngine VERSION 1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/bin")

# --- Add Subdirectories for Dependencies ---
add_subdirectory(lib/raylib)
add_subdirectory(vendor/flecs)
add_subdirectory(common/array_macros)
add_subdirectory(common/queue-macros)

# --- Main Executable Target ---
add_executable(ChimeraEngine)

# Associate source files directly with the target
target_sources(ChimeraEngine
    PRIVATE
    src/main.c
    src/actor.c
    src/actor_array.c
    src/actor_hash_map.c
    src/command.c
    src/command_queue.c
    src/command_result.c
    src/command_system.c
    src/component.c
    src/component_array.c
    src/game.c
    src/input_event_queue.c
    src/input_system.c
    src/log.c
    src/renderer.c
    src/world.c
)

# --- Configure Target Properties (Includes, Links, etc.) ---
target_include_directories(ChimeraEngine PRIVATE include)

# Define system-specific libraries for cross-platform compatibility
set(SYSTEM_LIBS "")
if (UNIX AND NOT APPLE)
    list(APPEND SYSTEM_LIBS m pthread) # Needed on Linux
endif()

target_link_libraries(ChimeraEngine
    PRIVATE
    raylib
    flecs
    array_macros
    queue_macros
    ${SYSTEM_LIBS}
)

# Set properties for a better IDE experience
set_target_properties(ChimeraEngine PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# --- Custom Run Target for Convenience ---
add_custom_target(run
    COMMAND $<TARGET_FILE:ChimeraEngine>
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ChimeraEngine
    COMMENT "Running ChimeraEngine from ${CMAKE_SOURCE_DIR}"
)
