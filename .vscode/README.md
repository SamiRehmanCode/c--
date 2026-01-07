# VS Code configuration files

This file documents the JSON files in the `.vscode` folder and explains how to use and customize them for this C/C++ workspace.

Files documented:

- `tasks.json` — Build, run and clean tasks used by VS Code Tasks
- `launch.json` — Debugging configurations for the C/C++ Debugger
- `c_cpp_properties.json` — IntelliSense and compiler settings for the C/C++ extension
- `settings.json` — Workspace-specific settings used by helper extensions

---

## `tasks.json`

Purpose: define reusable build/run/clean tasks that you can execute via "Tasks: Run Task" in VS Code.

Key tasks in this workspace:

- **Build Current C File**: compiles the active C file with debugging symbols using `C:/msys64/ucrt64/bin/gcc.exe` and writes the executable to the `build/` folder.
  - Important variables: `${file}` (current file), `${workspaceFolder}`, `${fileBasenameNoExtension}`
- **Build Current C++ File**: compiles the active C++ file using `C:/msys64/ucrt64/bin/g++.exe`.
- **Build Current C/C++ File (with pthread)**: compiles with `-pthread` for thread examples.
- **Run Current Program**: runs the executable from `build/` after building (depends on Build Current C File).
- **Clean Build Directory**: uses PowerShell `Remove-Item` to delete contents of the `build/` folder.

How to run:

1. Open a C or C++ file.
2. Press `Ctrl+Shift+P` → `Tasks: Run Task` → choose a task (e.g. "Build Current C File").

Customizing:

- Change the `command` paths to match your compiler installation if different than MSYS2 (`C:/msys64/ucrt64/bin/gcc.exe`).
- Adjust compiler flags in `args` (for optimization, sanitizers, etc.).

---

## `launch.json`

Purpose: configure debugging sessions for the C/C++ Debugger (`cpptools`).

Key configuration fields:

- `program`: path to the compiled executable — uses `${workspaceFolder}/build/${fileBasenameNoExtension}.exe` so it matches the name of the current file when built.
- `MIMode`: set to `gdb` to use the GNU debugger.
- `miDebuggerPath`: path to the `gdb` binary; if using MSYS2 provide the full path (e.g. `C:/msys64/ucrt64/bin/gdb.exe`) or ensure `gdb` is in PATH.
- `preLaunchTask`: task to run before debugging; currently set to `Build Current C File`.

Notes and tips:

- If you edit the `preLaunchTask`, make sure the task label matches exactly a task in `tasks.json`.
- If you want an external console for interactive stdin, set `externalConsole` to `true`.

---

## `c_cpp_properties.json`

Purpose: configure IntelliSense, include paths, compiler path, and language standards for the Microsoft C/C++ extension.

Important fields:

- `includePath`: directories scanned for header files and IntelliSense suggestions. It includes `${workspaceFolder}/**` and `${workspaceFolder}/include`.
- `compilerPath`: full path to the compiler (set to `C:/msys64/ucrt64/bin/gcc.exe`). This helps the extension detect system include paths and defines.
- `cStandard` / `cppStandard`: language standards used for parsing and IntelliSense (`c11`, `c++17`).
- `intelliSenseMode`: set to `windows-gcc-x64` for MSYS2/MinGW GCC.

Customizing:

- If you use another toolchain (MSVC, Clang), change `compilerPath` and `intelliSenseMode` accordingly.

---

## `settings.json`

Purpose: workspace-specific settings for helper extensions and tools (this workspace stores configuration for a C/C++ runner helper).

Key entries in this workspace:

- `C_Cpp_Runner.*` keys control a helper extension or script (compiler paths, standards, warnings, include paths, and options).

Notes:

- Update `C_Cpp_Runner.cCompilerPath` and `C_Cpp_Runner.cppCompilerPath` to the full MSYS2 compiler paths if you want the runner to find them reliably (e.g. `C:/msys64/ucrt64/bin/gcc.exe`).
- Modify `C_Cpp_Runner.includePaths` to add any project-specific headers.

---

If you'd like, I can:

- Add full absolute `gdb.exe` paths into `launch.json` (recommended) so debugging works out-of-the-box.
- Update `settings.json` compiler paths to `C:/msys64/ucrt64/bin/gcc.exe` and `C:/msys64/ucrt64/bin/g++.exe`.
- Provide quick examples of common modifications (e.g. enable address sanitizer) — tell me which one to add.

Files documented: `tasks.json`, `launch.json`, `c_cpp_properties.json`, `settings.json`.
