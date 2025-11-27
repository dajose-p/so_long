# so_long

<p align="center">
  <img src="https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white" alt="42 School"/>
  <img src="https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c" alt="Language C"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-green?style=flat-square" alt="MiniLibX"/>
</p>

## 📋 Description

**so_long** is a project that consists of creating a small 2D game where the player must collect all objects on the map and find the exit, avoiding obstacles. The project introduces fundamental concepts of graphics programming, event handling, and texture management.

The main objective is to learn how to work with the MiniLibX graphics library, handle keyboard and window events, and manage memory efficiently.

<p align="center">
  <img src="game.gif" alt="so_long gameplay" width="600"/>
</p>

## 🎮 Features

- **2D Rendering**: Use of sprites and textures in `.xpm` format
- **Player Movement**: Control using WASD or arrow keys
- **Collectible System**: The player must collect all items before exiting
- **Move Counter**: Displays the number of steps taken
- **Map Validation**: Verifies that the map is valid before starting the game
- **Memory Management**: Implementation without memory leaks

## 🛠️ Requirements

- **Operating System**: Linux or macOS
- **Compiler**: cc, gcc or clang
- **MiniLibX**: Graphics library (included in the project or installed on the system)
- **Make**: To compile the project

### Installing Dependencies (Linux)

```bash
sudo apt update
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

## 📦 Installation

1. Clone the repository:
```bash
git clone https://github.com/dajose-p/so_long.git
cd so_long
```

2. Compile the project:
```bash
make
```

3. Run the game:
```bash
./so_long <valid map>
```

## 🎯 Usage

### Controls

- **W / ↑**: Move up
- **A / ←**: Move left
- **S / ↓**: Move down
- **D / →**: Move right
- **ESC**: Exit the game

### Map Format

Maps must have a `.ber` extension and follow these rules:

- **1**: Wall
- **0**: Empty space
- **P**: Player's starting position (only one)
- **C**: Collectible (minimum one)
- **E**: Exit (only one)

#### Example of a valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Map Rules

- The map must be surrounded by walls (1)
- Must contain exactly one player (P) and one exit (E)
- Must have at least one collectible (C)
- A valid path must exist between the player, collectibles, and the exit
- All lines must have the same length

## 🔧 Makefile Commands

- `make`: Compiles the project
- `make clean`: Removes object files
- `make fclean`: Removes object files and executable
- `make re`: Recompiles the entire project
- `make play`: Play different maps as if they were levels

## 🎨 Textures

The textures used are `.xpm` files that represent:

- **Walls**: Blocks that delimit the map
- **Floor**: Space where the player can walk
- **Player**: Character sprite
- **Collectibles**: Items that the player must collect
- **Exit**: Door or exit portal

## ✅ Implemented Validations

- [x] Verification of `.ber` extension
- [x] Rectangular map
- [x] Map surrounded by walls
- [x] Valid path (flood fill algorithm)
- [x] Correct number of players, exits, and collectibles
- [x] Valid characters in the map
- [x] Memory management without leaks

## 🐛 Error Handling

The program handles the following errors:

- Map file not found
- Invalid map format
- Non-rectangular map
- Map not enclosed by walls
- Incorrect number of elements (P, E, C)
- No valid path exists
- Memory allocation errors

## 📝 Implementation Notes

- The project uses custom libft functions such as `ft_calloc`, `ft_strdup`, `get_next_line`
- Memory management is critical: all allocations must be properly freed
- It's important to close the window correctly to avoid MiniLibX leaks
- The flood fill algorithm validates that all collectibles and the exit are reachable

## 👤 Author

Daniel Jose Pereira - [@dajose-p](https://github.com/dajose-p)
