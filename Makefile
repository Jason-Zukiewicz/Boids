# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++20

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
MAIN_SRC = $(SRC_DIR)/main.cpp
GAME_SRC = $(SRC_DIR)/game/game.cpp
EVENTS_SRC = $(SRC_DIR)/events/eventHandler.cpp
OBJECT_SRC = $(SRC_DIR)/physics/object.cpp 
PHYSICS_SRC = $(SRC_DIR)/physics/physicsHandler.cpp 

# Object files
MAIN_OBJ = $(BUILD_DIR)/main.o
GAME_OBJ = $(BUILD_DIR)/game.o
EVENTS_OBJ = $(BUILD_DIR)/eventHandler.o
OBJECT_OBJ = $(BUILD_DIR)/object.o
PHYSICS_OBJ = $(BUILD_DIR)/physicsHandler.o 

# Executable name
EXEC = app

# SDL2 libraries
SDL_LIB = -lSDL2

all: $(EXEC)

$(EXEC): $(MAIN_OBJ) $(GAME_OBJ) $(EVENTS_OBJ) $(OBJECT_OBJ) $(PHYSICS_OBJ)
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/$@ $(SDL_LIB)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(GAME_OBJ): $(GAME_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(EVENTS_OBJ): $(EVENTS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_OBJ): $(OBJECT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(PHYSICS_OBJ): $(PHYSICS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)

clear:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)
