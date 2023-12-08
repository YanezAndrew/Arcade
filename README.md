# Arcade Game
By Brian Cheng, Kauri Mai, Andrew Yanez, Perry Thampiratwong

## About This Game
This game is a simple arcade game where the player must avoid obstacles in order to survive. The player can control their character by either using the mouse or the keyboard. As the game progresses, the obstacles will move faster and faster, making it harder to avoid them. To get the highest score, the player must survive for as long as they can by avoiding the obstacles that appear after a short warning period.

## General Info

### How to Play the Game
- The character is able to move up and down by either pressing the **up/down arrow keys** or by holding down the **left mouse button** and releasing it to move down.
- Press the **R** key to restart the game.
- Press the **Q** key to quit the game.

### Game Rules
- If the character goes out of bounds, it will be moved to the opposite side of the screen.
- Before a new obstacle appears, there will be a short warning period where the player can prepare to avoid it.
- As time progresses, both the character and the obstacles will move faster and faster, there will be more obstacles, and the warning period will be shorter.
- The game ends when the character collides with an obstacle.

## How to Run the Game
### CSIL/Linux
Build the exectuable with:
```
g++ util.cpp npc.cpp Character.cpp main.cpp texture.cpp background.cpp -lGL -lglut -lpng
```
If you get an error about the png library run the following command and then try building again:
```
sudo apt-get install libpng-dev 
``` 

### MacOS
Install Homebrew if you haven't already:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Then install the necessary libraries:
```
brew install freeglut xquartz
```

Build the exectuable with:
```
g++ -g util.cpp npc.cpp texture.cpp background.cpp Character.cpp main.cpp -framework OpenGL -framework GLUT -I/opt/homebrew/include -std=c++17 -lpng -L/opt/homebrew/lib -lz
```
If you get an error about the png library run the following command and then try building again:
```
brew install libpng
``` 

## Code Organization
### Player Code
The code governing the player object is mostly within Character.h and Character.cpp
1. In Character.h, all the getter/setters methods for the player's position and state are declared as well as any methods relating to user input.

2. In Character.cpp the `updateMovePosition()` checks the `movingUp` state of our player and adjusts its position accordingly. The `moveKey()` and `moveMouse()` methods check for their respective user inputs and updates the `movingUp` state depending on the input.

3. The `checkCollision()` method checks if the player has collided with an obstacle, and the `draw()` method draws the player on the screen.

### NPC Code
The code governing the NPC objects is mostly within npc.h and npc.cpp
1. There are two types of NPCs, warning signs that appear on the far right side of the screen and bullets, which emerge from the warning signs, move towards the player, and must be avoided.

2. NPCs contain two doubles that store the coordinates of their center point, a Type enum to determine the type of NPC. 

3. The main functions for each NPC are `draw()` and `move()`. `draw()` takes no parameters and checks whether the NPC is active, and then calls the specialized draw function for the NPC type to print it on the screen. The `move()` functions takes two doubles, dx and dy, and changes the center of the NPC by those respectively, if it goes outside the bounds of the screen, the center is reset to the opposite side that it was moving (moving off towards the left puts on the right side of the screen) 

### Miscellaneous\Helper Code
There are various miscellaneous\helper functions that are used throughout the codebase, such as drawing basic shapes, loading textures, and checking for collisions. These functions are located in util.h and util.cpp, texture.h and texture.cpp, and background.h and background.cpp respectively.
1. Background.h and background.cpp are simple helper files to create a textured background of the game
2. Texture.h and texture.cpp are used to load textures from png files and draw them on the screen
3. Util.h and util.cpp contain various helper functions such as drawing circles, rectangles, triangles, render text, randomly activate the bullet streams and draw the end screen

### Main Code
The main code is located in main.cpp and where the main game logic is located. 
1. The main function initializes the npcs and the game window and sets up the game loop, it also calls glut functions to handle user input.

2. To initialize the NPCs, the function `setupNPCs()` is called, which creates the warning signs and bullets and sets their initial positions. The game window is setup in the `Initialize()` function, which sets the window size and loads the textures for the endScreen, background, and player

3. The game loop is split between the `update()` and `display()` functions. `update()` is called every 33ms, which results in about 30fps, and while the game is not over, updates the positions of the player and NPCs, increases the points and difficulty, and checks for collisions. `display()` is also called every frame and draws the background, player, and NPCs on the screen. It also draws the end screen if the game is over.

4. User input is handled through GLUT functions. When the mouse is used, it calls the `mouse()` and `moveMouse()` function in Character.cpp, which checks if the left mouse button is pressed or released and updates the isMovingUp state accordingly. When the keyboard is used, it will call the proper keyboard related function to check if **R** is pressed to restart the game or if the **up/down arrow keys** are pressed to move the player up or down.