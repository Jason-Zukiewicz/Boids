# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++20 -Wno-comment -Wno-narrowing

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
MAIN_SRC = $(SRC_DIR)/main.cpp
GAME_SRC = $(SRC_DIR)/game/game.cpp
OBJECT_SRC = $(SRC_DIR)/physics/object.cpp 
PREY_SRC = $(SRC_DIR)/physics/prey.cpp 
PRED_SRC = $(SRC_DIR)/physics/pred.cpp 
FOOD_SRC = $(SRC_DIR)/physics/food.cpp 
PHYSICS_SRC = $(SRC_DIR)/physics/physicsHandler.cpp 

# Object files
MAIN_OBJ = $(BUILD_DIR)/main.o
GAME_OBJ = $(BUILD_DIR)/game.o
OBJECT_OBJ = $(BUILD_DIR)/object.o
PREY_OBJ = $(BUILD_DIR)/prey.o
PRED_OBJ = $(BUILD_DIR)/pred.o
FOOD_OBJ = $(BUILD_DIR)/food.o
PHYSICS_OBJ = $(BUILD_DIR)/physicsHandler.o 

# Executable name
EXEC = app

# SDL2 libraries
SDL_LIB = -lSDL2

all: $(EXEC)

$(EXEC): $(MAIN_OBJ) $(GAME_OBJ) $(OBJECT_OBJ) $(PRED_OBJ) $(PREY_OBJ)  $(FOOD_OBJ) $(PHYSICS_OBJ)
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/$@ $(SDL_LIB)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(GAME_OBJ): $(GAME_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_OBJ): $(OBJECT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(PREY_OBJ): $(PREY_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRED_OBJ): $(PRED_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(FOOD_OBJ): $(FOOD_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(PHYSICS_OBJ): $(PHYSICS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)

clear:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)
