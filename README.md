# Arcade Game

**Window Track: Brian Cheng, Kauri Mai, Andrew Yanez, Perry Thampiratwong**

**Player Track: Brian Cheng, Andrew Yanez**

**NPC Track: Kauri Mai, Perry Thampiratwong**

## About This Game

## Code Organization

For the **Player** Track, the code is split organized into Character.h/Character.cpp

1. In Character.h, all the getter/setters methods for the player's position and state are declared as well as any methods relating to user input.

2. In Character.cpp, the constructor sets the initial size of our player and sets its default state (no movement). The updateMovePosition() checks the movingUp state of our player and adjusts its position accordingly. This method also ensures that the player doesn't go out of bounds. The moveKey and moveMouse methods check for their respective user inputs and updates the movingUp state depending on the input.

Both tracks use main.cpp in order to display its respective objects and update their positions.

## How To Play

You can control your player in one of **two** ways...

1. **Mouse**

- _Hold_ the mouse down to move your character up
- _Release_ the mouse to move your character down

2. **Keyboard**

- _Press_ the up-arrow key to move your character up
- _Press_ the down-arrow key to move your character down

## How to Run The Game

To build the executable on **CSIL/Linux**...

```

g++ main.cpp Character.cpp util.cpp -lGL -lglut

```

To build the executable on **MacOS**...

```
g++ main.cpp Character.cp util.cpp -framework OpenGL -framework GLUT -I/opt/homebrew/include
```

To run the program...

```
./a.out
```

**Extra Installations For MacOS**

1. Install Homebrew

2. Then...

```
brew install freeglut xquartz
```
