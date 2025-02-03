
# Termo Text Editor

Termo is a simple, lightweight text editor built in C++ that allows you to create, edit, and save files directly from the terminal. It supports multiple modes including Insert Mode, Command Mode, and Visual Mode, allowing a flexible editing experience. The editor provides functionalities like cursor movement, file handling, and real-time editing.

## Features

- **Insert Mode**: 
  - Type text freely and move the cursor using the arrow keys.
  - Backspace to delete characters.
  - Supports creating and saving files.

- **Command Mode**: 
  - Save files, quit the editor, and open files for editing.
  - Execute specific commands like saving and quitting.

- **Visual Mode**: 
  - Supports basic navigation commands using the WASD keys.
  - Delete characters, lines, and more.

- **File Handling**: 
  - Open, create, and save files within the editor's directory.
  - Ability to load existing files into the editor and continue editing.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/termo.git
   ```

2. Compile the code using g++ or any C++ compiler:
   ```bash
   g++ -o termo Termo.cpp CommandMode.cpp TextInput.cpp
   ```

3. Run the editor:
   ```bash
   ./termo
   ```

## How to Use

1. **Open Termo**:
   - Launch Termo in your terminal.

2. **File Commands**:
   - Type `open` to list files in the current directory.
   - Enter the file name or number to open the desired file for editing.
   - Use `insert` to start editing the file in **Insert Mode**.
   - Use `save` to save your changes to the current file.
   - Use `q` to quit Termo.

3. **Insert Mode**:
   - Move the cursor with the arrow keys (`← ↑ → ↓`).
   - Type text normally, and use Backspace to delete.
   - Press Enter to create a new line.

4. **Command Mode**:
   - Type `!q` to force quit Termo without saving.
   - Use `w`, `a`, `s`, `d` to navigate the file.
   - Use `x` to delete characters.

5. **Visual Mode**:
   - Press `i` to toggle **Insert Mode**.
   - Use `z` and `r` for undo/redo operations (if implemented).

## Planned Features

- Undo/Redo functionality.
- Enhanced error handling for file operations.
- Support for additional commands (cut, copy, paste, etc.).

## Contributions

Feel free to fork the repository and submit pull requests for improvements. Contributions are welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.




# TermoVM
