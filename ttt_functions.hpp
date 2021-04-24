#include <vector>
#include <string>
using namespace std;

void display_grid(vector<vector<char>>& grid);
void player_move(vector<vector<char>>& arr, string player, char symbol);
bool check_winner(vector<vector<char>>& arr, char player1_symbol, char player2_symbol);