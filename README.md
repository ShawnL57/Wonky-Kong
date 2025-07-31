# Wonky Kong

## About The Project

Wonky Kong is a 2D platformer game developed in C++ using the OpenGL and FreeGLUT libraries. This project was created as part of the computer science curriculum at UCLA and is inspired by the classic arcade game, Donkey Kong. The game is built upon an object-oriented architecture, handling real-time game logic, collision detection, and sprite-based graphics rendering.

The game operates on a tick-based loop, processing user input, updating game object states, and rendering the scene at a consistent frame rate.

## Features

*   **2D Platformer Gameplay:** Navigate levels by running, jumping, and climbing ladders.
*   **Object-Oriented Design:** Game entities such as the player, enemies, and items are designed as distinct C++ classes.
*   **Collision Detection:** The game world manages interactions and collisions between different game objects.
*   **Sprite Animation:** Basic character animations are implemented using a series of sprites.
*   **Level System:** Game levels are loaded from text files, allowing for easy creation of new stages.

## Requirements

To build and run this project, you will need the following components installed on your system:

*   A C++ compiler that supports C++17 (e.g., g++, clang++)
*   `make` for build automation
*   FreeGLUT library
*   OpenGL libraries

For macOS, you can install FreeGLUT using Homebrew:
```bash
brew install freeglut
```
For Debian-based Linux distributions (like Ubuntu), you can use `apt`:
```bash
sudo apt-get install freeglut3-dev
```

## Getting Started

Follow these instructions to get a local copy up and running.

### Building the Game

1.  Clone the repository to your local machine.
2.  Navigate into the project directory.
3.  Compile the project using the provided Makefile:
    ```bash
    make
    ```

### Running the Game

After a successful compilation, an executable file named `WonkyKong` will be created. Run it with the following command:

```bash
./WonkyKong
```

## Controls

*   **Left/Right Arrow Keys:** Move the player character left or right.
*   **Up/Down Arrow Keys:** Climb up or down ladders.
*   **Spacebar:** Jump.
*   **Tab:** Use a special ability (Burp).

## Project Structure

The project is organized into the following key files:

*   `Actor.h` / `Actor.cpp`: Defines the base `Actor` class and all derived game entities, including the player, enemies, and items. This is where individual object behavior is implemented.
*   `StudentWorld.h` / `StudentWorld.cpp`: Manages the game world, including all active game objects, level loading, and collision detection logic.
*   `GameWorld.h` / `GameWorld.cpp`: Provides the top-level game state management and interfaces with the game controller.
*   `GameController.h` / `GameController.cpp`: A provided game engine interface that handles windowing, rendering, and user input.
*   `main.cpp`: The main entry point for the application.
*   `Makefile`: Contains the build instructions for the project.
*   `Assets/`: Contains all game assets, including sprites, sound files, and level layout files.
*   `README`: This documentation file.

## Academic Honesty Notice

This project was created as part of the coursework for UCLA's Computer Science curriculum. The source code is provided publicly for educational and showcase purposes only.

Any reuse of this code to complete similar assignments, submit as your own work, or otherwise violate academic integrity policies is strictly prohibited. If you are a student in a related course, you are expected to complete all assignments independently in accordance with your institution’s academic honesty guidelines.
