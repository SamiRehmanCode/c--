// Makefile for building all examples
# Usage: make [target]
# Targets: all, clean, basics, processes, threads, ipc, file_systems

CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -g -std=c11
CXXFLAGS = -Wall -Wextra -g -std=c++17
PTHREAD_FLAGS = -pthread

# Directories
SRC_DIR = src
BUILD_DIR = build

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Basic programs
basics: $(BUILD_DIR) $(BUILD_DIR)/hello $(BUILD_DIR)/system_info

$(BUILD_DIR)/hello: $(SRC_DIR)/basics/hello.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/system_info: $(SRC_DIR)/basics/system_info.c
	$(CC) $(CFLAGS) $< -o $@

# Process programs
processes: $(BUILD_DIR) $(BUILD_DIR)/fork_example

$(BUILD_DIR)/fork_example: $(SRC_DIR)/processes/fork_example.c
	$(CC) $(CFLAGS) $< -o $@

# Thread programs
threads: $(BUILD_DIR) $(BUILD_DIR)/basic_threads

$(BUILD_DIR)/basic_threads: $(SRC_DIR)/threads/basic_threads.c
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) $< -o $@

# IPC programs
ipc: $(BUILD_DIR) $(BUILD_DIR)/pipe_example

$(BUILD_DIR)/pipe_example: $(SRC_DIR)/ipc/pipe_example.c
	$(CC) $(CFLAGS) $< -o $@

# File system programs
file_systems: $(BUILD_DIR) $(BUILD_DIR)/file_operations

$(BUILD_DIR)/file_operations: $(SRC_DIR)/file_systems/file_operations.c
	$(CC) $(CFLAGS) $< -o $@

# Build all programs
all: basics processes threads ipc file_systems

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)/*

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build all programs"
	@echo "  basics       - Build basic programs"
	@echo "  processes    - Build process programs"
	@echo "  threads      - Build threading programs"
	@echo "  ipc          - Build IPC programs"
	@echo "  file_systems - Build file system programs"
	@echo "  clean        - Clean build directory"
	@echo "  help         - Show this help"

.PHONY: all clean basics processes threads ipc file_systems help