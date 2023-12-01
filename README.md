# Arcade Game

**Window Track: Brian Cheng, Kauri Mai, Andrew Yanez, Perry Thampiratwong**

**Player Track: Brian Cheng, Andrew Yanez**

**NPC Track: Kauri Mai, Perry Thampiratwong**

## About This Game

## Code Organization

For the **Player** Track, the code is split organized into Character.h/Character.cpp

1. In Character.h, all the getter/setters methods for the player's position and state are declared as well as any methods relating to user input.

2. In Character.cpp, the constructor sets the initial size of our player and sets its default state (no movement). The updateMovePosition() checks the movingUp state of our player and adjusts its position accordingly. This method also ensures that the player doesn't go out of bounds. The moveKey and moveMouse methods check for their respective user inputs and updates the movingUp state depending on the input.

For the **NPCs** Track, code is split mainly within npc.h/npc.cpp, but util.h/util.cpp were created for some basic utility functions such as drawing basic shapes as well

1. Currently there are 2 types of NPCs, warning signs and bullets with another obstacle NPC type planned

2. NPCs contain two doubles that store the coordinates of their center point, a Type enum to determine the type of NPC, and an bool called active to determine whether or not it is activated. The main functions for each NPC are `draw()` and `move()`. 

3. The `draw()` function takes no parameters and checks whether the NPC is active, and then calls the specialized draw function for the NPC type to print it on the screen. The `move()` functions takes two doubles, dx and dy, and changes the center of the NPC by those respectively, if it goes outside the bounds of the screen, the center is reset to the opposite side that it was moving (moving off towards the left puts on the right side of the screen)

* Both tracks use main.cpp in order to display its respective objects and update their positions.

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
g++ main.cpp npc.cpp Character.cpp -lGL -lglut
```

To build the executable on **MacOS**...

```
g++ main.cpp Character.cp util.cpp npc.cpp -framework OpenGL -framework GLUT -I/opt/homebrew/include
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
