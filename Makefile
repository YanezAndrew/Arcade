CC = g++
CFLAGS = -g -std=c++17 -I/opt/homebrew/include
LDFLAGS = -framework OpenGL -framework GLUT -lpng -L/opt/homebrew/lib -lz
LDFLAGS2 = -lGL -lglut -lpng

SRC = util.cpp npc.cpp texture.cpp background.cpp Character.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = arcadeMac
SECOND_EXECUTABLE = arcadeCsil

csil: $(SECOND_EXECUTABLE)

mac: $(EXECUTABLE)

$(SECOND_EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS2) -o $@

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE) $(SECOND_EXECUTABLE)