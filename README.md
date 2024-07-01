# Cards and Players Advanced Programming Project

## Overview

This repository contains the implementation of a card game as part of an advanced programming course assignment. The project demonstrates the use of C++ with object-oriented programming (OOP) principles and dynamic memory management.

## Project Description

The game is a single-player card game where the player battles against computer-controlled monsters. The player selects a character and an enemy, each with specific attributes and abilities. The game involves selecting and playing card sets to deal damage to the enemy or heal the player.

### Characters and Enemies

- **Characters:**
  - **Fighter:** 60 health points, 6 cards maximum.
  - **Sorcerer:** 40 health points, 8 cards maximum.
  - **Ranger:** 50 health points, 7 cards maximum.

- **Enemies:**
  - **Troll:** 100 health points, deals 5 damage.
  - **Ghost:** 50 health points, deals 15 damage.
  - **Dragon:** 75 health points, deals 10 damage.

### Game Mechanics

- **Card Sets:**
  - Valid sets are either a single card or multiple cards of the same rank whose total value is less than or equal to 10.
  - Special card suits (diamonds, hearts, clubs, spades) have unique effects during play.

- **Gameplay:**
  - The player selects and plays cards from their hand each turn.
  - The game calculates damage dealt to the enemy and healing for the player based on the card set played.
  - Each enemy has specific interactions with the player’s abilities based on the card suits.

## Features

- **Object-Oriented Programming (OOP):** Utilizes classes and inheritance to define the game’s characters, enemies, and card mechanics.
- **Dynamic Memory Management:** Proper handling of dynamic memory allocation and deallocation to prevent memory leaks and errors.
- **C++ Standard Library:** Utilizes features from the C++ Standard Library for efficient and effective programming.

## Getting Started

To compile and run the project, follow these steps:

1. **Clone the repository:**
    ```
    git clone https://github.com/Yarin-Shohat/Cards-and-Players.git
    ```
2. **Navigate to the project directory:**
    ```
    cd Advanced-Programming-Project
    ```
3. **Compile the project:**
    ```
    make
    ```
4. **Run the executable:**
    ```
    ./Decks_game
    ```

## Project Structure

- `main.cpp`: Contains the main function to start the game.
- `Card.cpp` / `Card.h`: Defines the Card class and related functions.
- `Character.cpp` / `Character.h`: Defines the Character class and derived classes for different character types.
- `Enemy.cpp` / `Enemy.h`: Defines the Enemy class and derived classes for different enemy types.
- `Game.cpp` / `Game.h`: Contains the game logic and mechanics.

## Memory Management

The project handles dynamic memory allocation using:
- **Smart Pointers:** To automatically manage memory and ensure no memory leaks.
- **Exception Handling:** To gracefully handle errors and exceptions during memory allocation and other operations.

## Contribution

Contributions are welcome! Fork the repository and create a pull request with your improvements or bug fixes.
