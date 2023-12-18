#Tool definitions
CC ?= gcc
CXX ?= g++

#Directories
SOURCE_DIR	:= ./
BUILD_DIR	:= build
OBJ_DIR		:= build/obj
NAME		:= list

#Search path for header files
CFLAGS += 

#Compiler flags
CFLAGS += -Wall -g

#Linker flags
LDFLAGS += 

.PHONY: all $(NAME) clean

all: $(BUILD_DIR)/$(NAME)

#Build target
$(BUILD_DIR)/$(NAME): $(OBJ_DIR)/main.o $(OBJ_DIR)/$(NAME).o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/$(NAME).o -o $@

#Build object files in the obj directory
$(OBJ_DIR)/$(NAME).o: $(SOURCE_DIR)/$(NAME).c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Build main
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir -p $@
	
clean:
	rm -rf $(BUILD_DIR)



