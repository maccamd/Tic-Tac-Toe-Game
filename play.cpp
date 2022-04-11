#include <iostream>
#include "ttt.hpp"

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction(){
    std::cout << " ------------------\n";
    std::cout << " Naught and Crosses\n";
    std::cout << " ------------------\n\n";

    std::cout << "Intoduction\n\n";
    std::cout << "There are two players who will put either a x or o on a tile on a 3x3 grid.\n";
    std::cout << "First player to get 3 in a row wins the game!\n\n";
    std::cout << "Player 1 is x\n";
    std::cout << "Player 2 is o\n\n";
    
    std::cout << " The Grid \n";
    std::cout << "   |   |   \n";
    std::cout << " 1 | 2 | 3 \n";
    std::cout << "---|---|---\n";
    std::cout << " 4 | 5 | 6 \n";
    std::cout << "---|---|---\n";
    std::cout << " 7 | 8 | 9 \n";
    std::cout << "   |   |   \n";

    std::cout << "Press [Enter] to start\n";
    std::cin.ignore();
}

void game(){
    while (!is_winner() && !board_full()){

    take_turn();
    set_marker();
    change_player();
    draw();
    }
    
}

bool is_winner() {

  bool winner = false;
  // rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
    winner = true;
  } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
    winner = true;
  } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
    winner = true;
  } 
  // columns
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
    winner = true;
  } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
    winner = true;
  } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
    winner = true;
  } // diagonals
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
    winner = true;
  }
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
    winner = true;
  }

  return winner;

}

void draw(){
    std::cout << "   |   |   \n";
    std::cout <<  " " << board[0] << " | "<< board[1] << " | " << board[2] << "  \n";
    std::cout << "---|---|---\n";
    std::cout <<  " " << board[3] << " | "<< board[4] << " | " << board[5] << "  \n";
    std::cout << "---|---|---\n";
    std::cout <<  " " << board[6] << " | "<< board[7] << " | " << board[8] << "  \n";
    std::cout << "   |   |   \n";
}

void take_turn(){
    std::cout << "Player " << player << " pick a square from 1-9\n";
    std::cin >> position; 
}

void set_marker(){
    if (board[position-1] == "x" && "o"){
        std::cout << "Sorry that space is already taken, please pick again\n";
        std::cout << "Player " << player << " pick a square from 1-9\n";
        std::cin >> position; 
    }
    if (player == 1){
        board[position-1] = "x";
    }else{
        board[position-1] = "o";
    }
    std::cout << "\n";
}

void change_player(){
    if (player == 1){
        player++;
    }else{
        player--;
    }
}

bool board_full(){
    bool complete = true;
    for (int i=0; i < 9; i++){
        if (board[i] == " "){
            complete = false;
        }
    }
    return complete;
} 

void winner(){
     if (is_winner()) {
         if (player == 2){
             player--;
         }else{
             player++;
         }
    std::cout << "There's a winner! Player " << player << "\n";
  }
  else if (board_full()) {
    std::cout << "There's a tie!\n";
  }

}