# Minimalist Text Editor in C

This project is a simple and minimalist text editor written in pure C. It allows users to edit a specified line in a text file by providing the line number. The editor then overwrites the selected line with the user's input while preserving the rest of the file's content.

---

## Features

- **View File Contents**: Displays the content of the text file line by line with line numbers for easy reference.
- **Edit Specific Lines**: Allows editing of a specific line in the file by specifying its line number.

---

## How to Use

### Step 1: Clone the Repository
Clone the repository to your local machine:
```bash
git clone <repository_url>
cd <repository_directory>
```

### Step 2: Compile the Program
Use GCC or another C compiler to compile the source code:
```bash
gcc -o editor editor.c
```

### Step 3: Run the Program
Run the compiled program with the name of the text file to edit:
```bash
./editor <filename.txt>
```
```cmd
editor.exe <filename.txt>
```

## Notes
The editor handles files up to 1024 bytes in size; larger files may require modifications to the buffer size in the code.
