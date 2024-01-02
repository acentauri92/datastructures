CC := gcc

#List of directories
SRC_DIR 	:= src
INCLUDE_DIR := inc
BUILD_DIR 	:= build
OBJ_DIR 	:= build/obj

CFLAGS := -g3 -O0
LD_FLAGS:= 

SOURCES := $(wildcard $(SRC_DIR)/*.c)

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean btree

# Build targets (Directories are order only deps)
$(BUILD_DIR)/btree: $(OBJECTS)
	$(CC) $(LD_FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

#Create directories
$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir $@

clean:
	rm -rf $(BUILD_DIR)