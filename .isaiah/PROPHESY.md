# Prophesy

## Guiding Statement

Chimera Engine shall be a specialized, data-driven, and highly modular C-based framework designed for the creation of procedurally generated, turn-based games with deep, systemic simulation.

## Foundational Principles

1.  **Systemic Simulation Core:** The engine's foundation is a robust architecture for modeling complex, interconnected systems, powered by an ECS. This high-performance, cache-friendly Entity-Component-System enables emergent behavior from the interaction of simple, independent parts, allowing the simulation to be the primary driver of the game world.

2.  **Data-Driven Procedural Generation:** The engine will provide a powerful and flexible framework for procedural content generation (PCG). All engine systems, from world layout to item creation, will be driven by external data definitions. The goal is to empower designers to create vast, coherent, and surprising worlds by composing and tweaking generation rules without modifying the core engine code.

3.  **Decoupled & Agnostic Architecture:** The engine will make no assumptions about narrative or plot. Instead, its core loop, state management, and event systems will be designed to be completely agnostic. It will provide the tools to log, query, and react to world events, enabling the game layer to interpret the output of the simulation as an emergent narrative.

4.  **Dynamic Capabilities System:** The engine will be built around a flexible command and component system that allows an entity's available actions ("verbs") to be modified at runtime. This modular design will prevent hardcoded classes and allow for the creation of transformative progression systems where new components grant entirely new capabilities.

5.  **Multi-Scale Architecture:** The engine's world management and rendering pipeline will be designed with scale fidelity in mind. It must be architecturally capable of managing multiple, distinct simulation scopes (e.g., a tile-based location, a region map, a solar system view) and providing the hooks to transition between them seamlessly.

## Precedents & Influences

-   ***Caves of Qud:*** Serves as the primary inspiration for a deeply systemic and moddable architecture. We will study its approach to component-based objects and data-driven inheritance as a technical benchmark.
-   ***Dwarf Fortress:*** Establishes the gold standard for procedural world-building that goes beyond mere geography. The engine's PCG systems must be capable of generating and simulating abstract historical and cultural data. Its success also validates that a rich simulation can be effectively represented through a pure tile-based renderer.
-   ***Factorio:*** Provides the architectural model for extreme moddability. The engine should be designed such that the "base game" is effectively the first mod, with core logic driven by accessible data files. This data-driven approach is paramount for fostering a creative community.
-   ***Cogmind:*** Sets the benchmark for a modern terminal aesthetic. The engine's rendering module must provide the tools to achieve this level of clarity, information density, and polished "ASCII-plus" presentation, including support for animations and particle effects within the grid.
-   ***The `Cataclysm: DDA` action system:*** Provides the benchmark for a granular and flexible turn-based action and event system. Its philosophy of enabling complex interactions through a vast set of simple, composable actions is a key driver for our own command system design.
