# Wonky Kong

## Table of Contents
- [Overview](#overview)
- [Gameplay](#gameplay)
- [Game Objects](#game-objects)
- [Controls](#controls)
- [Scoring System](#scoring-system)
- [Installation](#installation)
- [Development and Implementation](#development-and-implementation)
- [Technical Details](#technical-details)
- [Resume Highlights](#resume-highlights)
- [Future Enhancements](#future-enhancements)

## Overview
Wonky Kong is a retro-inspired platformer game that serves as a modern reinterpretation of the classic Donkey Kong arcade game. The game is a modern reinterpretation of the classic Donkey Kong arcade game, with additional mechanics, enemies, and player abilities. The player controls a plumber navigating through multiple levels filled with ladders, platforms, and various hazards to ultimately reach Kong and progress to the next level.

## Gameplay
In Wonky Kong, the player aims to climb ladders, dodge rolling barrels, avoid fireballs and Koopas, and collect power-ups to increase lives or gain temporary burping power. Each level is designed as a 20x20 grid consisting of platforms, ladders, enemies, and collectible items. The game continues until the player either completes all levels or loses all lives.

### Key Features:
- Classic platformer mechanics with modern enhancements
- Multiple levels with increasing difficulty
- Player abilities include jumping, burping, and climbing
- Enemy types: Barrels, Fireballs, Koopas
- Power-ups: Extra Life Goodies and Garlic Goodies
- Scoring system based on defeating enemies and collecting goodies

## Game Objects
- **Player:** The main character controlled by the user. Can jump, move left/right, climb ladders, and burp to attack enemies.
- **Kong:** The main antagonist, throwing barrels at the player and fleeing once the player reaches its platform.
- **Barrels:** Rolling hazards thrown by Kong, reversing direction upon landing and incinerating upon contact with Bonfires.
- **Fireballs:** Enemies that move horizontally and can occasionally climb ladders.
- **Koopas:** Turtle-like enemies that can freeze the player temporarily.
- **Bonfire:** Stationary hazard that burns barrels and kills the player on contact.
- **Ladder:** Allows vertical movement for both player and some enemies.
- **Floors:** Platforms the player and enemies can walk on.
- **Extra Life Goodie:** Grants an additional life to the player upon collection.
- **Garlic Goodie:** Provides 5 burps to the player upon collection.
- **Burp:** A projectile that temporarily lingers and can destroy enemies.

## Controls
- **Arrow Keys:** Move left/right, climb ladders
- **Spacebar:** Jump
- **Tab:** Burp (if burps are available)

## Scoring System
- Defeating a Barrel: 100 points
- Defeating a Fireball: 100 points
- Defeating a Koopa: 100 points
- Collecting a Garlic Goodie: 25 points
- Collecting an Extra Life Goodie: 50 points
- Reaching Kong and completing the level: 1000 points

## Installation
1. Clone the repository:

```bash
git clone [repository-url]
```

2. Navigate to the project directory:

```bash
cd wonky-kong
```

3. Compile the project:

```bash
make
```

4. Run the game:

```bash
./wonky-kong
```

## Development and Implementation
The game was developed using C++ with object-oriented principles to structure the game’s components effectively. Key aspects of the development include:

- Object-Oriented Design: Implemented a hierarchy of actor classes to manage different game objects such as the Player, Kong, Barrels, Fireballs, Koopas, and more.
- Collision Detection: Utilized bounding box checks to handle interactions between actors.
- Game Loop: Implemented a consistent game loop to manage actor states and ensure smooth animation.
- Randomized Enemy Behavior: Employed pseudo-random number generation to introduce variability in enemy actions.
- Memory Management: Managed dynamic allocation and deallocation of game objects to prevent memory leaks.

## Technical Details
- Programming Language: C++
- Game Framework: custom-built C++ framework for game object management and collision detection
- Data Structures: std::vector, std::list
- Inheritance: Implemented base and derived classes for each actor type
- File Handling: Level data loaded via text files
- Sound Effects: Managed using predefined constants (e.g., SOUND_ENEMY_DIE, SOUND_GOT_GOODIE)
- Random Number Generation: Utilized the `randInt` function for enemy behaviors
- Debugging Tools: GDB, Valgrind
- Animation: Managed using the `increaseAnimationNumber()` function for graphical effects
- **Languages Used:** C++
- **Game Framework:** custom-built C++ framework for game object management and collision detection
- **Data Structures:** STL containers (e.g., std::vector, std::list)
- **Game Objects and Inheritance:** Implemented using OOP principles with base and derived classes for actors
- **Collision Handling:** Implemented through bounding box checks and state management
- **Randomized Enemy Behavior:** Implemented using pseudo-random number generation

## Resume Highlights
- Designed and implemented a complex game environment using OOP principles in C++
- Developed custom actor classes including Player, Kong, Fireballs, Koopas, and Barrels
- Implemented collision detection, enemy behavior, and a scoring system
- Enhanced user experience with smooth animation, sound effects, and responsive controls
- Applied object-oriented design patterns to optimize game logic and prevent code duplication

## Future Enhancements
- Additional enemy types and power-ups
- Enhanced level designs with more complex layouts
- Multiplayer support
- Additional scoring mechanics

-----
