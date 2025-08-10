# Morse Code Converter

A simple interactive Morse code converter written in C, supporting bidirectional conversion between Morse code and English text.

---

## Features

- Convert Morse code (using `.` and `-`) to English.
- Convert English sentences into Morse code.
- Interactive console interface with toggle between modes (press **Tab** to switch).
- Supports spaces between letters and `/` between words.
- Designed for Windows console environment using Windows API for input handling.

---

## Requirements

- **Windows OS** with a C compiler (e.g., [MinGW-w64](https://www.mingw-w64.org/))  
- Windows console environment (Command Prompt or PowerShell) to run properly.

---

## Building and Running on Windows

1. Ensure `mcui.h` and its implementation file (e.g., `mcui.c`) are in the project directory.  
2. Compile using MinGW (or Visual Studio):

   ```bash
   gcc main.c mcui.c -o morse.exe
