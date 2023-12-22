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

COBJECTS := $(patsubst $(SOURCE_DIR)/%.c, $(OBJ_DIR)/%.o, \
			$(wildcard $(SOURCE_DIR)/*.c))

.PHONY: all $(NAME) clean leakcheck

all: $(BUILD_DIR)/$(NAME)

#Build target
$(BUILD_DIR)/$(NAME): $(COBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(COBJECTS) -o $@

#Build object files in the obj directory
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir -p $@
	
clean:
	rm -rf $(BUILD_DIR)

leakcheck:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
	--show-reachable=yes $(BUILD_DIR)/$(NAME)



