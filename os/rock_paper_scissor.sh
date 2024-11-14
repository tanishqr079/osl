#!/bin/bash

# Function to get the computer's choice
get_computer_choice() {
  choices=("Rock" "Paper" "Scissors")
  echo "${choices[$((RANDOM % 3))]}"
}

# Function to determine the winner
determine_winner() {
  if [ "$player" == "$computer" ]; then
    echo "It's a draw! You both chose $player."
  elif { [ "$player" == "Rock" ] && [ "$computer" == "Scissors" ]; } ||
       { [ "$player" == "Paper" ] && [ "$computer" == "Rock" ]; } ||
       { [ "$player" == "Scissors" ] && [ "$computer" == "Paper" ]; }; then
    echo "You win! $player beats $computer."
  else
    echo "You lose! $computer beats $player."
  fi
}

# Display menu
while true; do
  echo "Rock, Paper, Scissors Game"
  echo "1. Play"
  echo "2. Exit"
  read -p "Enter your choice (1-2): " choice

  case $choice in
    1)
      # Get player's choice
      echo "Choose one:"
      echo "1. Rock"
      echo "2. Paper"
      echo "3. Scissors"
      read -p "Enter your choice (1-3): " player_choice

      case $player_choice in
        1) player="Rock" ;;
        2) player="Paper" ;;
        3) player="Scissors" ;;
        *) 
          echo "Invalid choice, please try again."
          continue
          ;;
      esac

      # Get computer's choice
      computer=$(get_computer_choice)

      # Display choices
      echo "You chose: $player"
      echo "Computer chose: $computer"

      # Determine the winner
      determine_winner
      ;;
    2)
      echo "Goodbye!"
      exit 0
      ;;
    *)
      echo "Invalid choice, please try again."
      ;;
  esac
done
