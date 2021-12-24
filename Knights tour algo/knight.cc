//Adam Dubsky
//CS3610
//Project 3
//October 2021

//reference links
//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
//https://en.wikipedia.org/wiki/Knight%27s_tour#:~:text=A%20knight's%20tour%20is%20a,visits%20every%20square%20exactly%20once.&text=The%20knight's%20tour%20problem%20is,given%20to%20computer%20science%20students.
//book page 390

#include <iostream>
#include <iomanip>


#include "knights_tour.h"


using namespace std;

//initial row/column for next value
//int temp_row_moves[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
//int temp_col_moves[8] = { 1, 2, 2, 1, -1, -2, -2, -1};

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

//used to move() function
void KnightsTour::get_moves(
  //Use to get the location of possible moves
  int row, int col, 
  //stores the location of valid rows/columns 
  //num_moves used as counter to keep track of the size 
  int row_moves[], int col_moves[], int& num_moves 
) {
    //Initilize the temporary rows using values for next
    int temp_row_moves[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
    int temp_col_moves[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
    

    int x_row = 0; //row moves variable
    int y_column = 0; //column moves variable

    //for loop to fill variable values
    for (int i = 0; i < 8; i++)
    {
      x_row = temp_row_moves[i] + row;
      y_column = temp_col_moves[i] + col;

      //if statement to check if moves are valid, updates array and counter if the move is valid
      //makes sure does not move off board andn xy = 0
      if (y_column >= 0 && y_column < 5 && x_row>= 0 && x_row < 5 && board[x_row][y_column] == 0)
      {
        col_moves[num_moves] = y_column;
        row_moves[num_moves] = x_row;

        //update counter
        num_moves++;
      }
      

    }
    




}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.


//Tour moves off by 1? figure out how to fix
void KnightsTour::move(int row, int col, int& m, int& num_tours) {

  //initialize variables
  int num_moves = 0;
  int col_moves[8];
  int row_moves[8];

  //set/update the board
  //must update the m value so starts at 1
  m = m + 1;
  board[row][col] = m;

  //call get_moves function to find valid moves
  get_moves(row, col, row_moves, col_moves, num_moves);

  //recursive call in for loop for the next call
  for (int i = 0; i < num_moves; i++)
  {
    move(row_moves[i], col_moves[i], m, num_tours);	
  }

  //base case
  //solution found when m == 25
  if (m == 25)
  {
    //must update number of tours one more time here
    num_tours++;
    print();
  }
  
  //backtracking for accuracy
  board[row][col] = 0;
  m--;
  
  
  
 

  

  

  
}



int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
