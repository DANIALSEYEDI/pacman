# 🎮 Pac-Man (C Language) - Final Project

This project is a simple version of the classic **Pac-Man** game, implemented in C language as a final project for the "Introduction to Computer and Programming" course at Amirkabir University of Technology.

## 🧠 Project Goals

The objectives of this project are:
- Strengthen understanding of basic programming concepts such as data structures, algorithms, and control flow.
- Learn to work with the terminal to create a user interface.
- Understand how to design simple games and implement their logic in C.

## 🕹️ Game Features

- Interactive menu with options: Start Game, View Records, Exit
- Pac-Man movement using arrow keys
- 2D map rendering and scalable map design
- Randomly distributed stars on the map
- Two types of ghosts with different behaviors:
  - Random movement (wandering)
  - Player-chasing (targeted AI)
- Life system and Game Over upon ghost collision
- Special items:
  - 🍒 Cherry: enables Pac-Man to eat ghosts
  - 🌶️ Pepper: increases speed
  - 🍎 Apple: adds extra life
  - 🍄 Poison Mushroom: decreases a life
- Score saving with timestamp and display of top 10 players
- Three difficulty levels: Easy, Medium, Hard
- Visual and sound effects to enhance user experience
- Gameplay recording and replay system

## 🛠️ Technologies Used

- C Programming Language
- Console-based UI (Terminal)
- Standard C libraries (stdio.h, stdlib.h, etc.)

## 🚀 Getting Started

To compile and run the game:
```bash
gcc -o pacman main.c -lm
./pacman
```

Ensure you have a GCC compiler and terminal support for optimal experience.

## 📁 Project Structure

- `main.c` - Entry point and main loop
- `game.c / game.h` - Game logic and functions
- `map.c / map.h` - Map generation and rendering
- `utils.c / utils.h` - Helper functions and constants
- `record.c / record.h` - Record saving and loading