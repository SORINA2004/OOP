
# File Versioning and Snapshot System

## Overview

This application provides a file versioning and snapshot system that allows users to track changes made to files in a directory, commit changes, and manage different file snapshots. The program supports basic functionalities like committing changes with a message, viewing file information, checking the status of the files compared to the last snapshot, and returning to previous snapshots.

## Features

1. **Commit Changes**: You can commit your changes with a message. The program will copy the current files to a snapshot directory.
2. **File Information**: View detailed information about the files in the directory (e.g., word count, character count, method count, etc.) for `.txt` and `.cpp` files.
3. **Status Check**: Compare the current files with the last snapshot and show which files have been modified, added, or removed.
4. **Return to Previous Snapshot**: Allows you to revert the directory to a previous snapshot by selecting the desired snapshot from a list of saved commits.
5. **Automatic Change Detection**: Periodically checks for changes in the directory and logs the status.

## How It Works

### Main Program Loop

The program continuously prompts the user with the following options:

1. **Commit**: Allows you to save the current state of the directory to a snapshot with a commit message.
2. **Info**: Displays information about the files (word count, character count, method count, etc.) in the monitored directory.
3. **Status**: Displays the differences between the current files and the last committed snapshot.
4. **Return to Snapshot**: Allows you to restore the directory from a previous snapshot.
5. **Exit**: Exits the program.

### Change Detection

The program runs an asynchronous task `RunChangeDetector` which continuously checks for changes every 10 seconds. When a change is detected, the `Status()` method is called to compare the current state of files with the most recent snapshot.

### File Comparison

For each file in the current directory and the snapshot, the program compares:

- **For `.txt` files**: The number of lines, words, and characters.
- **For `.cpp` files**: The number of lines of code, methods, and classes. It also identifies added or removed methods or classes.
- **New or Deleted Files**: The program also identifies files that have been newly added or deleted.

### Snapshots

Each commit creates a snapshot of the directory, which is stored in a designated commits folder. You can view the list of all snapshots and restore any of them at any time.

### Error Handling

The program includes basic error handling to catch exceptions and display appropriate messages to the user if any issues occur.

## File Structure

- **root**: The path of the directory being monitored for changes.
- **commitdir**: The path where snapshots (commits) are stored.

## Example Usage

When the program is running, it shows the following options:

```
1. Commit.
2. Info.
3. Status.
4. Return to previous snapshots.
5. Exit
Choose an option:
```

### Example Commit

When choosing the "Commit" option, the program will ask for a message and then save the current directory state:

```
Message: Fix bug in main.cpp
```

### Example Info

The "Info" option will display file information for all `.txt` and `.cpp` files in the monitored directory.

---

This README file provides a high-level overview of how the program works and the main features. Let me know if you need more details or further clarification!