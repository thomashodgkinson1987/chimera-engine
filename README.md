![Chimera Engine Banner](./.github/assets/chimera-banner.png)

# Chimera Engine

Chimera Engine is a specialised, data-driven, and highly modular C-based framework designed for the creation of procedurally generated, turn-based games with deep, systemic simulation.

## Core Features

*   **Systemic Simulation Core:** Powered by the Flecs ECS framework to enable deep, emergent gameplay.
*   **Data-Driven by Design:** All aspects of the engine, from entity creation to world generation, are driven by external data files, making it highly moddable.
*   **Decoupled & Agnostic:** A clean C API with a modular architecture, including a swappable backend for rendering and input (currently using Raylib).
*   **Turn-Based Focus:** A built-in Command Pattern game loop perfect for creating complex, turn-based roguelikes.

## Getting Started

### The Easy Way (Recommended)

This repository includes a complete Dev Container configuration. This is the fastest and most reliable way to get a fully-configured development environment.

1.  Make sure you have Docker, VS Code, and the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) installed.
2.  Clone the repository: `git clone --recurse-submodules https://github.com/thomashodgkinson1987/chimera-engine.git`
3.  Open the cloned folder in VS Code.
4.  When prompted, click "**Reopen in Container**".

VS Code will automatically build the Docker image and launch a terminal inside the container with all dependencies pre-installed. You can then proceed to the build steps.

### The Manual Way (Native Build)

If you prefer to build on your host machine, you will need to install the necessary toolchain for the engine itself, as well as the libraries required to build its dependencies (primarily Raylib) from source.

**1. Core Development Toolchain**

You will need a modern C/C++ development environment. Chimera Engine is written in C17, but its dependencies may require a C++ compiler.

*   **C/C++ Compiler Suite:** A compiler supporting C17 (e.g., `gcc`, `clang`, `MSVC`). A C++ compiler is also required by the build process for dependencies (`g++`, `clang++`).
*   **CMake:** Version 3.10 or higher is required to generate the build files.
*   **Git:** Required for cloning the repository and its submodules.
*   **Debugger (Recommended):** A debugger like `gdb` or `lldb` is essential for development.

**2. Raylib Backend Dependencies**

The default rendering and input backend, Raylib, requires a number of system libraries for windowing, graphics, and audio. The exact package names will vary depending on your operating system and distribution.

On a typical Linux system, you will need the development headers for:
*   OpenGL (`mesa-libGL-devel`)
*   ALSA (for audio)
*   X11 (for windowing, including libraries like Xrandr, Xi, Xcursor, etc.)

**For a definitive list of required packages**, please consult the official [Raylib wiki for your OS](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) or, for the exact versions used in our reference environment, refer to the `Dockerfile` in this repository.

### Building the Engine

The following instructions assume you are running commands from the project's root directory.

#### For Linux

These steps describe a typical native debug build.

1.  **Configure CMake:**
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    ```
2.  **Build the code:**
    ```bash
    cmake --build build
    ```
3.  **Run the executable:**
    To ensure the application starts in the correct directory to find its assets, use the provided `run` convenience target. This is the recommended way to launch the engine.
    ```bash
    cmake --build build --target run
    ```

#### For Windows (Cross-compiling from Linux)

These steps describe how to build a Windows executable from a Linux environment using the MinGW toolchain.

1.  **Configure CMake:**
    This command points to a separate build directory and specifies the Windows toolchain file.
    ```bash
    cmake -S . -B build/windows -DCMAKE_TOOLCHAIN_FILE=toolchain-windows.cmake -DCMAKE_BUILD_TYPE=Debug
    ```
2.  **Build the code:**
    ```bash
    cmake --build build/windows
    ```
3.  **Run the executable:**
    The final executable (`ChimeraEngine.exe`) will be located in a path structured by environment and build type (e.g., `build/windows/Windows/Debug/bin/`).

    To run it, you will need to use an environment that can execute Windows binaries, such as Wine on Linux or by transferring the build output to a Windows machine. Note that, like the Linux version, it must be run with the project's root as the working directory to locate assets correctly.

## For Contributors & Deeper Dives

This project maintains a high standard of internal documentation for developers and contributors. To learn more, please see the following documents:

*   **[Project Overview](/.tabernacle/PROJECT-OVERVIEW.md):** The detailed architectural blueprint of the engine.
*   **[Prophesy](/.isaiah/PROPHESY.md):** The long-term vision and guiding principles for the project.
*   **[Style Guide](STYLE-GUIDE.md):** Our coding and Git contribution standards.
*   **[Milestones](MILESTONES.md):** The high-level development roadmap.

## License

Chimera Engine is licensed under the **LGPLv3**. Please see the `LICENSE` file for the full text.

The licenses for all third-party dependencies are aggregated in the `THIRD-PARTY-LICENSES.md` file.
