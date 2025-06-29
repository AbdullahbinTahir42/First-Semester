# 🎮 Character Crush Saga

**Character Crush Saga** is a console-based game built with C++. It offers a fun, interactive experience with three difficulty levels: Easy, Medium, and Hard. Players must strategically match and replace characters on a grid to score points and progress through levels.

---

## 📌 Features

- Three difficulty levels with increasing grid sizes
- Interactive text-based interface
- Score tracking and level progression
- User information storage (name, age, email)
- Game manual and strategy tips
- Developer and game guide sections

---

## 🗂️ File Structure

| File          | Description                                            |
|---------------|--------------------------------------------------------|
| `main.cpp`    | Main game logic, UI, and function calls                |
| `user.txt`    | Stores player details (name, age, email)               |

---

## ⚙️ Dependencies

This project uses standard C++ libraries:
- `iostream` – Console I/O
- `cstdlib` – Random character generation
- `ctime` – Time seeding for randomness
- `conio.h` – Keyboard input (may be compiler-specific)
- `fstream` – File input/output for user data

---

## 🧠 Key Functions

| Function                   | Description                                     |
|----------------------------|-------------------------------------------------|
| `rand_char()`              | Generates random characters                     |
| `easy_initial_board()`     | Sets up the Easy mode board (6×6)               |
| `med_initial_board()`      | Sets up the Medium mode board (8×8)             |
| `hard_initial_board()`     | Sets up the Hard mode board (10×10)             |
| `easy_player_turn()`       | Handles player moves in Easy mode               |
| `med_player_turn()`        | Handles player moves in Medium mode             |
| `hard_player_turn()`       | Handles player moves in Hard mode               |
| `easy_update_board()`      | Updates Easy mode board after a move            |
| `med_update_board()`       | Updates Medium mode board after a move          |
| `hard_update_board()`      | Updates Hard mode board after a move            |
| `mode_selection()`         | Lets the player choose difficulty mode          |
| `main_menu()`              | Displays main menu and routes game options      |

---

## 🎮 Gameplay Instructions

1. Run the game.
2. Enter your name, age, and email.
3. Agree to the terms and conditions.
4. Choose a game mode: Easy, Medium, or Hard.
5. Follow on-screen instructions to make moves and score points.
6. Check the manual or playing technique for help.

---

## 🧾 Scoring & Progression

- Each mode has unique scoring rules and board mechanics.
- Progress through three levels by completing objectives.
- Game ends when you win or exhaust your moves.

---

## 📘 Additional Sections

- **Game Manual** – In-depth guide on gameplay
- **Playing Technique** – Strategy tips for players
- **Developers Info** – Meet the creators behind the game

---

## ❌ Exit Game

To quit the game, select the **"Exit"** option from the main menu.

---

## 👨‍💻 Developers

Visit the "Developers" section in-game to learn about the creators and contributors of this project.

---

## 📥 Getting Started

1. Clone the repo:
   ```bash
   git clone https://github.com/your-username/character-crush-saga.git
   cd character-crush-saga
