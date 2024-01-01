# Get the absolute path of the Makefile and the project and test directories.
# Reference: https://matheusmbar.com/bugfree-robot/2019/04/05/makefile-first-test.html

MAKEFILE_DIR	:= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR		:= $(realpath $(MAKEFILE_DIR)..)
TEST_DIR		:= $(PROJECT_DIR)/test
TEST_BUILD_DIR	:= build
CPPUTEST_HOME := $(TEST_DIR)/cpputest

# Set variables needed by Cpputest helper Makefile.
# See cpputest/build/MakefileWorker.mk
INCLUDE_DIRS	:=  $(PROJECT_DIR)/inc $(CPPUTEST_HOME)/include
SRC_DIRS		:= $(PROJECT_DIR)/src
TEST_SRC_DIRS	:= $(TEST_DIR)/src

COMPONENT_NAME := $(TEST_BUILD_DIR)/queue
CPPUTEST_OBJS_DIR := $(TEST_DIR)/$(TEST_BUILD_DIR)
CPPUTEST_LIB_DIR := $(TEST_DIR)/$(TEST_BUILD_DIR)

# Run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

