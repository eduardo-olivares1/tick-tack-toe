#include <iostream>
#include <vector>
#include <cstdlib>
#include "ttt_functions.hpp"
#include <string>

using namespace std;


int main(){
  vector<vector<char>> values = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

  bool game_over = false;
  int moves = 0;
  char player1_symbol = 'x'; 
  char player2_symbol = 'o';

  while(game_over != true){
    if (moves == 0){
      display_grid(values);
    }
    player_move(values, "Player 1", player1_symbol);
    display_grid(values);
    game_over = check_winner(values, player1_symbol, player2_symbol);

    if (game_over == true){
      return 0;
    }

    
    player_move(values, "Player 2", player2_symbol);
    game_over = check_winner(values, player1_symbol, player2_symbol);
    display_grid(values);
    if (game_over == true){
      return 0;
    }
    moves++;
  }

  

  return 0;


}




