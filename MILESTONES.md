# Project Milestones

This document outlines the major development milestones for the Chimera Engine. Each milestone represents a self-contained, demonstrable piece of functionality.

---

## Milestone 1: The Lonely @

**Status:** In Progress

*Goal: A controllable player character exists on a static, pre-defined map, proving the core engine loop is functional.*

### Key Features & Systems

- [ ] **Build System:** CMake is configured to produce `libchimera.so` and a separate game executable.
- [ ] **ECS Integration:** The Flecs library is successfully integrated and used for all entity management.
- [ ] **Core Entity:** Create a `Player` entity with `Position` {x, y} and `Renderable` {glyph, color} components.
- [ ] **Basic Renderer:** A system iterates over all entities with `Position` and `Renderable` components and draws them to the screen using the Raylib adaptor.
- [ ] **Basic Input:** An input system reads keyboard presses and creates "Move" commands.
- [ ] **Command Execution:** The command system processes "Move" commands and updates the `Position` component of the `Player` entity.

> **Definition of Done:** When launching the game, a window appears showing an '@' symbol. The user can press the arrow keys to move the '@' around the screen. The game can be closed cleanly.

---

## Milestone 2: A Room with a View

**Status:** Not Started

*Goal: The player exists within a bounded level and can only see what's within their line of sight, introducing concepts of map architecture and visibility.*

### Key Features & Systems

- [ ] **Map System:** Load a simple, static map from a text file or hardcoded array into a map data structure.
- [ ] **Collision System:** Implement a system that prevents movement commands from being executed if the target tile is a solid wall.
- [ ] **Camera System:** The view is centered on the player entity, and the map scrolls as the player moves.
- [ ] **FOV Algorithm:** Implement a core FOV calculation function within `libchimera` (the pure algorithm).
- [ ] **Visibility System:** Create a system that uses the FOV algorithm to add/remove an `IsVisible` component from map tiles each turn. The renderer now only draws entities and tiles with this component.

> **Definition of Done:** The player is confined to the walkable areas of a pre-defined map. As the player moves, parts of the map are revealed or hidden. The player cannot see around corners.

---

## Milestone 3: An Interactive World

**Status:** Not Started

*Goal: The player can interact with the world in a meaningful way beyond movement, introducing the foundational mechanics for most roguelikes.*

### Key Features & Systems

- [ ] **Actor & Turn System:** Introduce the concept of an `Actor` component and a simple energy-based turn system. Only entities with the `Actor` component can take actions.
- [ ] **First NPC:** Add a stationary NPC to the map. It is an entity with `Position`, `Renderable`, and `Actor` components.
- [ ] **Door Mechanic:** Create "Door" entities with an `Openable` component {is_open: bool}. Implement an "Open" command that changes this state.
- [ ] **Item Mechanic:** Create "Item" entities and an `Inventory` component for the player. Implement "Pick Up" and "Drop" commands.

> **Definition of Done:** The player can walk up to a closed door, press a key to open it, and walk through. The player can walk over an item to pick it up and can press a key to drop it from their inventory.
