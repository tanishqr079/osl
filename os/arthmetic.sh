#!/bin/bash

# Function to perform addition
add() {
  echo "Result: $(($1 + $2))"
}

# Function to perform subtraction
subtract() {
  echo "Result: $(($1 - $2))"
}

# Function to perform multiplication
multiply() {
  echo "Result: $(($1 * $2))"
}

# Function to perform division
divide() {
  if [ $2 -ne 0 ]; then
    echo "Result: $(($1 / $2))"
  else
    echo "Error: Division by zero is not allowed."
  fi
}

# Display menu
echo "Select operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read -p "Enter your choice (1-4): " choice

# Input numbers
read -p "Enter first number: " num1
read -p "Enter second number: " num2

# Perform operation based on user choice
case $choice in
  1)
    add $num1 $num2
    ;;
  2)
    subtract $num1 $num2
    ;;
  3)
    multiply $num1 $num2
    ;;
  4)
    divide $num1 $num2
    ;;
  *)
    echo "Invalid choice. Please select a valid operation."
    ;;
esac
