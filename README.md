


# Simple File Manager for Windows

This project is a console-based file manager developed in C for Windows. It provides a basic yet interactive command-line interface (CLI) for managing files and directories. The file manager uses color-coded output and includes loading animations to improve the user experience.

## Features

- **List Files:** Display files and directories in a specified folder.
- **Create Files:** Create new files at the given file path.
- **Delete Files:** Remove existing files from the system.
- **Colored Output:** Each operation uses different colors for clarity (e.g., errors in red, directories in blue).
- **Loading Animations:** Smooth loading animations are displayed before each action.
- **Interactive CLI:** Simple and easy-to-use menu system with clear prompts and responses.

## Requirements

- **Windows OS**: The file manager uses the Windows API, so it is compatible only with Windows systems.
- **C Compiler**: You need a C compiler such as GCC, MinGW, or Visual Studio to compile the code.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/awad1236/simple-file-manger-
   cd simple-file-manger-
   ```

2. Compile the project:
   - Using GCC (MinGW):
     ```bash
     gcc mian.c operation.c -o filemanager.exe
     ```


## Usage

1. Run the executable:
   ```bash
   ./filemanager
   ```

2. Use the menu to select your desired operation:
   - **1**: List files in a directory.
   - **2**: Create a new file.
   - **3**: Delete an existing file.
   - **4**: Exit the program.

3. Example Interaction:

   ```
   Loading File Manager Options...
   ...
   1. List files in directory
   2. Create a file
   3. Delete a file
   4. Exit
   Enter your choice: 1
   ```

## Code Highlights

- **Colored Output**: The `setColor()` function is used to change text color in the terminal.
- **Loading Animation**: The `loadingAnimation()` function displays dots with a delay to simulate loading or processing.
- **File Operations**:
   - **`listFiles()`**: Lists all files and subdirectories in a specified directory.
   - **`createFile()`**: Creates a file at the specified path.
   - **`deleteFile()`**: Deletes the specified file from the system.

<br/>

# Feel free to fork, contribute, and provide feedback on improvements!


