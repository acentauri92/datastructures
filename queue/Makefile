#Tool definitions
CC ?= gcc
CXX ?= g++

#Directories
SOURCE_DIR := ./
BUILD_DIR := build
OBJ_DIR := build/obj
NAME := queue

#Search path for header files
CFLAGS += 

#Compiler flags
CFLAGS += -Wall -g

#Linker flags
LDFLAGS += 

.PHONY: all $(NAME) clean queue

all: $(BUILD_DIR)/$(NAME)

#Build queue
$(BUILD_DIR)/$(NAME): $(OBJ_DIR)/main.o $(OBJ_DIR)/queue.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/queue.o -o $@

$(OBJ_DIR)/queue.o: $(SOURCE_DIR)/queue.c | $(OBJ_DIR)
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



