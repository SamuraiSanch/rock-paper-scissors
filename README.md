# ✂️ Rock Paper Scissors

A classic console game built in C++ where you compete against the computer. Each player starts with 3 lives — lose a round and you lose a life. First to lose all lives loses the game!

## 📋 Description

**Rock Paper Scissors** is a turn-based game against the computer. The computer's choice is powered by a random number generator (`std::mt19937`), making each round unpredictable.

The game uses a **lives system** — both you and the computer start with 3 lives. This makes each game more tense than a single-round match.

## 🎯 Gameplay Rules

- Both players start with **3 lives**
- Each round you pick **Stone, Scissors, or Paper**
- **Stone** beats Scissors, **Scissors** beats Paper, **Paper** beats Stone
- Loser of a round loses **1 life**
- Draw — no one loses a life
- First to lose all **3 lives** loses the game
- After each game, you can choose to play again

## 🛠️ Technologies

- **C++11**
- **`enum class`:** `RoundResult` and `GameOptions` for type-safe game logic
- **`<random>`:** `std::mt19937` + `std::uniform_int_distribution` for fair random generation
- **Input validation:** `std::cin.fail()` handling with recovery via `cin.clear()` / `cin.ignore()`

## 🚀 How to Run

### Compilation (GCC/Clang):
```bash
g++ -std=c++11 rock-paper-scissors.cpp -o rock-paper-scissors
./rock-paper-scissors
```

### Compilation (Visual Studio):
1. Open the project in Visual Studio
2. Press `F5` (Run)

## 📂 Project Structure

```
rock-paper-scissors/
└── rock-paper-scissors.cpp    # Full game logic
```

## 📋 Example Usage

```
Welcome to the game Rock Paper Scissors!
=== Game statistics now ===
Player lives: 3
Computer lives: 3
What you choose?
Options:
1) Stone,
2) Scissors,
3) Paper.
: 1
Computer chose: Scissors
You won this round, congrats!
=== Game statistics now ===
Player lives: 3
Computer lives: 2
...
You're winner, congrats!
Do you want to play again? (Y)es, (N)o: N
```

## 🔧 Future Improvements

- [ ] Display computer's choice as text instead of a number
- [ ] Configurable number of lives
- [ ] Score tracking across multiple sessions
- [ ] Multiplayer (two human players)
- [ ] GUI version

## 👤 Author

**Oleksandr Kopii**  
GitHub: [@SamuraiSanch](https://github.com/SamuraiSanch)

---
⭐ If you enjoyed this project, feel free to leave a star!
