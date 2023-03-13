//Assignment 3
//Author:Kevin Masson
//This is a program to use a back tracking search algorithm
//to solve the N-Queens problem

#include<iostream>

using namespace std;

//NOTE: to change the number of queens, change these 3 numbers
//this makes it way easier than using a vector all the time
const int Q = 8;
int board[8][8];

void initialize();
void print();
bool backTrack(int);
bool check(int, int);


int main() {
//set up the board with zeros
initialize();

//begin the recursive backtrack algorithm
//if solution is found it will print the board
//else it will say there is no solution
if (backTrack(0)) {
  cout << "Solution found: \n";
  print();
  } else {
    cout << "No solution found";
  }
return 0;
}

//function to initialize the board with zeros
//NOTE: I actually have no idea if you need to do this step
//since I assume its initialized to 0 anyway, but I already coded it
//so I'm just going to leave it here
void initialize() {
  for (int i = 0; i<Q; i++) {
    for (int j = 0; j<Q; j++) {
      board[i][j] = 0;
    }
  }
}

//function to print the current state of the board, queens will be
//denoted with a 'Q'
void print() {
  for (int i = 0; i<Q; i++) {
    for (int j = 0; j<Q; j++) {
      if (board[i][j] == 0)
        cout << board[i][j] << " ";
      else
        cout << "Q" << " ";
    }
    cout << endl;
  }
}

//function for back track search algorithm
bool backTrack(int c) {
  //if algorithm has passed the end of the board, a solution is found
  if (c == Q)
    return true;

  //iterates through each row and checks for a plausible solution
  for (int i = 0; i < Q; i++) {
    //if the current spot is valid it will place a queen
    if (check(i, c)) {
      board[i][c] = 1;

      //iterates to the next column to see if there is a solution for the
      //current queen placement
      if (backTrack(c+1))
        return true;

      //if there is no acceptable solution, the board is reset and iterates
      //to the next row
      board[i][c] = 0;
    }
  }

  //if there is no solutions it will return false
  return false;
}

//function for checking the current move to see if it is valid, will check
//all columns to the left as there have been placements to the right
bool check(int r, int c) {

  //checks to see if any queens are in the current row
  for (int i = 0; i<c; i++) {
    if (board[r][i] == 1)
      return false;
  }

  //checks to see if there are any queens to the upper right
  for (int i = r, j = c; i>=0 && j>=0; i--, j--) {
    if (board[i][j] == 1)
      return false;
  }

  //checks to see if there are any queens to the lower right
  for (int i = r, j = c; i < Q && j >= 0; i++, j--) {
    if (board[i][j] == 1)
      return false;
  }

  //if all checks are valid, it returns true as a valid move
  return true;
}
