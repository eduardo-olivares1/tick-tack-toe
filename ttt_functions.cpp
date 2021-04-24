#include <vector>
#include <iostream>
#include <string>

using namespace std;

void display_grid(vector<vector<char>> &grid)
{
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[i].size(); j++)
    {
      if (j == 2)
      {
        cout << "  " << grid[i][j] << "  \n";
      }
      else
      {
        cout << "  " << grid[i][j] << "  |";
      }
    }
  }
}

void player_move(vector<vector<char>> &arr, string player, char symbol)
{
  cout << player << " is making their move... \n";
  bool turn_over = false;

  while (turn_over == false)
  {
    //Player1 makes a random choice
    int index1 = 0;
    int index2 = 0;
    cout << "Select X coordinate then press enter:";
    cin >> index1;
    cout << "Select Y coordinate then press enter:";
    cin >> index2;

    if (arr[index1][index2] != 'x' && arr[index1][index2] != 'o' && arr[index1][index2] == ' ')
    {
      arr[index1][index2] = symbol;
      turn_over = true;
    }
    else
    {
      cout << "\nThat space is not empty. Please choose another\n";
    }
  }
}

bool check_winner(vector<vector<char>> &arr, char player1_symbol, char player2_symbol)
{
  //8 Ways to Win
  //3 Across the x axis
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
    {
      if (arr[i][0] == player1_symbol)
      {
        cout << "Player 1 Wins!\n";
        return true;
      }
      else if (arr[i][0] == player2_symbol)
      {
        cout << "Player2 Wins!\n";
        return true;
      }
    }
  }
  //3 Across the y axis
  for (int i = 0; i < arr[0].size(); i++)
  {
    if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
    {
      if (arr[0][i] == player1_symbol)
      {
        cout << "Player 1 Wins!\n";
        return true;
      }
      else if (arr[0][i] == player2_symbol)
      {
        cout << "Player2 Wins!\n";
        return true;
      }
    }
  }

  //2 Diagonol
  //Might be a better way to do this but this will do for now
  if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
  {
    if (arr[0][0] == player1_symbol)
    {
      cout << "Player 1 Wins!\n";
      return true;
    }
    else if (arr[0][0] == player2_symbol)
    {
      cout << "Player2 Wins!\n";
      return true;
    }
  }
  else if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2])
  {
    if (arr[2][0] == player1_symbol)
    {
      cout << "Player 1 Wins!\n";
      return true;
    }
    else if (arr[2][0] == player2_symbol)
    {
      cout << "Player2 Wins!\n";
      return true;
    }
  }

  return false;
}
