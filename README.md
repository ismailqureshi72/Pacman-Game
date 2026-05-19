# Pacman Game

A classic Pacman game implementation in C++ using the **SFML** (Simple and Fast Multimedia Library). This was built as part of an Object-Oriented Programming (OOP) project.

## 🎮 Features
- **Classic Gameplay**: Navigate the maze, eat dots, and avoid enemies.
- **Multiple Game States**: Includes Menu, Play, Pause, Color Change, and Exit screens.
- **Object-Oriented Design**: Clean class structures for `player`, `enemies`, `maze`, and `movement`.
- **Audio & Visuals**: Utilizes `.ogg` audio files and custom fonts/graphics using SFML.

## 🛠️ Technologies Used
- **Language**: C++
- **Library**: SFML (Simple and Fast Multimedia Library)
- **IDE**: Visual Studio (using the `.sln` and `.vcxproj` files provided)

## 🚀 Getting Started

### Prerequisites
To build and run this project, you need:
- **Visual Studio** (2019, 2022, or newer) with C++ development tools installed.
- **SFML Library** set up on your machine (configured in your Visual Studio include/lib paths).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/ismailqureshi72/Pacman-Game.git
   ```
2. Open `OOP Project.sln` in Visual Studio.
3. Ensure that your SFML include and library directories are correctly linked in the project properties.
4. Set the build configuration (e.g., `Debug` or `Release` for `x64` or `x86` depending on your SFML setup).
5. Build and run the project!

## 🕹️ Controls
- Use the **Arrow Keys** (Up, Down, Left, Right) to move Pacman.
- Follow in-game menu prompts for pausing or changing game settings.

## 📁 Project Structure
- `main.cpp` - Contains the main game loop and state management.
- `background.png`, `bg.jpg`, `pacman.png` - Game assets.
- `High Speed.ttf` - Custom font used for the UI.
- `.ogg.opus` files - Audio assets.

## 📝 License
See the `License.txt` file for license rights and limitations.
