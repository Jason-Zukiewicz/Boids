CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lSDL2 -lSDL2main

SRC_DIR = src
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
EXECUTABLE = $(BUILD_DIR)/app

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
