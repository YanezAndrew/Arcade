# Arcade Game

To build the executable on **CSIL/Linux**...
```
g++ main.cpp -lGL -lglut
```

To build the executable on **MacOS**...
```
g++ main.cpp -framework OpenGL -framework GLUT -I/opt/homebrew/include
```


To run the program...
```
./a.out
```

On mac:
1) brew install install xquartz 
2) brew install freeglut (If that doesn't work lmk, I may have used another command)