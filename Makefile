# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++20
LDFLAGS = -lSDL2 -lSDL2main

# Executable
TARGET = build/app


# Directories
BLDDIR = build
SRCDIR = src
GAMEDIR = $(SRCDIR)/game
HANDDIR = $(SRCDIR)/handler
OBJDIR = $(SRCDIR)/object

# Object files
OBJS =  $(HANDDIR)/eventHandler.o $(GAMEDIR)/game.o  $(OBJDIR)/object.o

# Source files
SRCS = $(SRCDIR)/main.cpp



# Rules
all: $(TARGET)

$(TARGET): $(OBJS) $(SRCS)
	$(CC) -o $(TARGET) $(OBJS) $(SRCS) $(CFLAGS) $(LDFLAGS)

$(GAMEDIR)/%.o: $(GAMEDIR)/%.cpp $(GAMEDIR)/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(HANDDIR)/%.o: $(HANDDIR)/%.cpp $(HANDDIR)/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR)/%.o: $(OBJDIR)/%.cpp $(OBJDIR)/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET)

clear:
	rm -f $(TARGET)
