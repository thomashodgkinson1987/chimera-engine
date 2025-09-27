# Project Overview

## High-Level Summary

-   **Project:** Chimera Engine
-   **Developer:** Thomas Hodgkinson (Tom)
-   **Email:** thomashodgkinson1987@gmail.com

## Architecture

-   **Model:** A data-oriented design powered by the **Flecs Entity-Component-System (ECS) framework**. This approach favors composition over inheritance and ensures a performant, cache-friendly core.
-   **Core Concepts:**
    -   **Entities:** Simple integer IDs that represent all game objects (player, items, tiles, etc.).
    -   **Components:** Pure data structs (`Position`, `Health`, `Renderable`) that are attached to entities to define their properties.
    -   **Systems:** The logic of the engine, written as functions that query and operate on entities with specific sets of components.
-   **Game Loop:** The engine's logic is built on a **Command Pattern** that works in tandem with the ECS.
    -   *Systems* (e.g., AI, Input) generate "Commands" (atomic state change requests).
    -   A central queue in the `command_system` module holds these commands.
    -   A `command_execute` function processes commands, which in turn modifies the *Components* of *Entities*.
    -   The main game loop checks the results of command execution to handle consequences (e.g., logging, triggering other systems).

## Git Repositories

-   **Main Project:** `https://github.com/thomashodgkinson1987/chimera-engine.git`
-   **`raylib` Submodule:** `https://github.com/raysan5/raylib.git` (housed in `/lib/`)
-   **`flecs` Submodule:** `https://github.com/SanderMertens/flecs.git` (housed in `/vendor/`)
-   **`array_macros` Submodule:** `https://github.com/thomashodgkinson1987/array_macros.git` (housed in `/common/`)
-   **`queue_macros` Submodule:** `https://github.com/thomashodgkinson1987/queue-macros.git` (housed in `/common/`)

## Build & Run Workflow

### Building for Linux (Native)

**Dependencies:** `git`, `cmake`, and a C11-compliant compiler (e.g., `gcc` or `clang`).

1.  **Configure:**
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    ```
2.  **Build:**
    ```bash
    cmake --build build
    ```
3.  **Build & Run:**
    ```bash
    cmake --build build --target run
    ```
4.  **Debug:** To launch a debugging session, press `F5` in VS Code (uses `.vscode/launch.json`).

The final executable's location will follow the pattern: `build/<environment>/Linux/<buildType>/bin/ChimeraEngine`, where `<environment>` is `host` or `container` and `<buildType>` is your chosen build type (e.g., `Debug`).

### Building for Windows (Cross-Compilation from Linux)

**Dependencies:** `mingw-w64-gcc` and `mingw-w64-gcc-c++`.

1.  **Configure:**
    ```bash
    cmake -S . -B build/windows -DCMAKE_TOOLCHAIN_FILE=toolchain-windows.cmake -DCMAKE_BUILD_TYPE=Debug
    ```
2.  **Build:**
    ```bash
    cmake --build build/windows
    ```

The final executable's location will follow the pattern: `build/<environment>/Windows/<buildType>/bin/ChimeraEngine.exe`, using the same `<environment>` and `<buildType>` logic.

## Directory Structure

The project is organised into the following key files and directories:

-   `/.cubit/`: Manages the project's task-based workflow using a Markdown-based Kanban system. It contains the following key files:
    -   `KANBAN-BACKLOG.md`: A list of task cards waiting in the queue to be worked on.
    -   `KANBAN-CURRENT.md`: Contains the single task card that is currently in progress.
    -   `KANBAN-COMPLETED.md`: A reverse-chronological log of all completed task cards.
    -   `TASK-CARD-TEMPLATE.md`: A template for the summary 'cards' that populate the Kanban boards, linking to the detailed task file.
    -   `tasks/TASK-TEMPLATE.md`: The comprehensive template for a new detailed task document, to be saved in the `/tasks/` subdirectory.
-   `/.devcontainer`: Holds configuration for developing inside a VS Code Dev Container.
-   `/.github/`: Contains GitHub-specific files, like workflow actions for CI/CD.
-   `/.isaiah/`: Contains the high-level project vision and guiding principles (`PROPHESY.md`).
-   `/.tabernacle/`: Contains foundational documents that define the context and workflow for the AI pair-programming collaboration.
    -   `AI-PERSONA.md`: Defines the AI's identity (Rubix), role, directives, and modes of operation.
    -   `BOOTSTRAP-GUIDE.md`: The master instruction set for the AI to follow at the start of every session to gain full project context.
    -   `CLI-BOOTSTRAP.md`: A wrapper script for initiating an AI session in a local command-line environment.
    -   `DEVELOPER-PERSONA.md`: Defines the human developer's identity, collaborative style, and working patterns.
    -   `HANDOFF-TEMPLATE.md`: A structured template for creating detailed handoff reports to ensure continuity between development sessions.
    -   `NOTES.md`: A scratchpad for transient notes and thoughts during a development session.
    -   `PROJECT-OVERVIEW.md`: A copy of the root-level project overview, placed here for easy access during the AI's bootstrap sequence.
    -   `WEB-BOOTSTRAP.md`: A wrapper script for initiating an AI session in a web-based environment where direct file access is not possible.
-   `/.vscode/`: Contains project-specific settings and launch configurations for VS Code.

-   `/build/`: Build output directories (generated by CMake, ignored by Git).
-   `/common/`: Contains reusable, first-party libraries (e.g., `array_macros`), often managed as submodules.
-   `/include/`: Public engine header files (`.h`), organised by module (e.g., `core/`, `renderer/`).
-   `/lib/`: Contains the Raylib source submodule for the rendering and IO backend.
-   `/res/`: Contains game assets like fonts, images, and data files.
-   `/src/`: Core C source files (`.c`), organised by module to mirror the `include` directory.
-   `/vendor/`: Contains third-party source submodules, such as Flecs.

-   `CMakeLists.txt`: The root CMake file for building the entire project.
-   `Dockerfile`: Defines a container image for a consistent build environment.
-   `LICENSE`: Contains the full text of the LGPLv3 and GPLv3 licenses.
-   `MILESTONES.md`: A living document outlining the major development milestones for the project.
-   `MILESTONE-TEMPLATE.md`: A blank template for creating new entries in `MILESTONES.md`.
-   `README.md`: The primary entry point for new visitors to the repository.
-   `start-vscode-on-host.sh`: A utility script for launching VS Code on the host machine.
-   `STYLE-GUIDE.md`: Defines the coding style and conventions for the project.
-   `THIRD-PARTY-LICENSES.md`: Aggregates the copyright notices and license texts for all third-party libraries (e.g., Raylib, Flecs) for legal compliance.
-   `toolchain-windows.cmake`: CMake toolchain file for cross-compiling to Windows.

-   `.gitignore`: Specifies files and directories to be ignored by Git.
-   `.gitmodules`: Defines the Git submodules used in the project.
