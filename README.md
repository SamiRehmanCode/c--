# System Programming with C/C++

This workspace is set up for practicing system programming concepts from university coursework.

## Directory Structure

````
c++/
├── src/                    # Source files
│   ├── basics/            # Basic C/C++ programs
│   ├── processes/         # Process-related programs
│   ├── threads/           # Threading examples
│   ├── ipc/              # Inter-process communication
│   ├── signals/          # Signal handling
│   ├── networking/       # Network programming
│   └── file_systems/     # File system operations
├── include/               # Header files
├── build/                 # Compiled executables
├── exercises/            # Practice exercises
└── resources/            # Reference materials

## How to Use

1. **Compile individual programs:**
   ```bash
   gcc -o build/program_name src/folder/program.c
````

2. **Compile C++ programs:**

   ```bash
   g++ -o build/program_name src/folder/program.cpp
   ```

3. **Use VS Code tasks:**
   - Press `Ctrl+Shift+P` and type "Tasks: Run Task"
   - Select "Build Current File" or "Run Current File"

## System Programming Topics Covered

- Process creation and management
- Thread programming and synchronization
- Inter-process communication (pipes, shared memory, message queues)
- Signal handling
- File I/O and file systems
- Network programming (sockets)
- Memory management
- System calls

## Prerequisites

- GCC/G++ compiler
- Make (optional)
- VS Code with C/C++ extension

## Getting Started

1. Start with basic examples in `src/basics/`
2. Progress through topics as you study
3. Practice exercises are in the `exercises/` folder
4. Use the VS Code integrated terminal for compilation and execution
