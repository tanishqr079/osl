#!/bin/bash

# Function to display the menu
show_menu() {
  echo "Select an operation:"
  echo "1. Copy a file"
  echo "2. Move a file"
  echo "3. Rename a file"
  echo "4. Delete a file"
  echo "5. Exit"
}

# Function to copy a file
copy_file() {
  read -p "Enter source file path: " src
  read -p "Enter destination path: " dest
  if [ -f "$src" ]; then
    cp "$src" "$dest"
    echo "File copied successfully."
  else
    echo "Source file does not exist."
  fi
}

# Function to move a file
move_file() {
  read -p "Enter source file path: " src
  read -p "Enter destination path: " dest
  if [ -f "$src" ]; then
    mv "$src" "$dest"
    echo "File moved successfully."
  else
    echo "Source file does not exist."
  fi
}

# Function to rename a file
rename_file() {
  read -p "Enter current file path: " src
  read -p "Enter new file name: " dest
  if [ -f "$src" ]; then
    mv "$src" "$(dirname "$src")/$dest"
    echo "File renamed successfully."
  else
    echo "File does not exist."
  fi
}

# Function to delete a file
delete_file() {
  read -p "Enter file path to delete: " file
  if [ -f "$file" ]; then
    rm "$file"
    echo "File deleted successfully."
  else
    echo "File does not exist."
  fi
}

# Main program loop
while true; do
  show_menu
  read -p "Enter your choice (1-5): " choice
  case $choice in
    1)
      copy_file
      ;;
    2)
      move_file
      ;;
    3)
      rename_file
      ;;
    4)
      delete_file
      ;;
    5)
      echo "Exiting..."
      exit 0
      ;;
    *)
      echo "Invalid choice. Please try again."
      ;;
  esac
done
