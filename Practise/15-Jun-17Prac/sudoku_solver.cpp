#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

const int n = 9;

bool isSafe(int board[n][n], int row, int col, int num) {
	int i;
	for(i=0;i<n && i!=row;++i){
		if(board[i][col] == num)	return false;
	}

	for(i=0;i<n && i!=col;++i){
		if(board[row][i] == num)	return false;
	}

	int j;

	for(i=0; i<3; ++i) {
		for(j=0 ;j<3; ++j){
			int row_index = (row-row%3) + i;
			int col_index = (col-col%3) + j;
			if(row_index<n && col_index<n && board[row_index][col_index] == num)
				return false;
		}
	}

		return true; 	// Ab sahi hai
}


bool sudoku_solver(int board[n][n], int curr_row, int curr_col) {
	int i, j;

	// first we find empty row and column
	for(i = curr_row; i<n; ++i) {
		for( j = curr_col;j<n;++j) {
			if(!board[i][j])	break;
		}
	}

	if(i >=n && j>=n)
		return true;	//soln exists

	curr_row = i;
	curr_col = j;

	for(i=1;i<=9;++i) {
		if(isSafe(board, curr_row, curr_col, i)){
			// kuch kuch ho sakta hai
			board[curr_row][curr_col] = i;

			if(sudoku_solver(board, curr_row, curr_col))	//yahan don't do curr_row+1 or curr_col+1 because we dont know ki row incrase karna hai ki column increase karna hai. First for loop apne aap dhund lega ki kahanse place karna shuru karna hai
			{
				return true;
			}
			board[curr_row][curr_col] = 0;//number hata do. i.e. backtrack
		}
	}
	return false;	// board[curr_row][curr_col] pe rakhne se kuch ni hua.
}

void printBoard(int board[n][n]) {
	for(int i=0;i<n;++i){	//typo on 16-Jun-17. Used +i instead of ++i. caused an infinite loop
		for(int j =0;j<n;++j)
			cout <<board[i][j]<<' ';

		cout << endl;
	}
}

int main() {
	freopen("sudoku_solver.in", "r", stdin);
	int board[n][n]= {};

	for(int i =0 ;i<n;++i) {
		for(int j = 0;j<n;++j)
			cin >> board[i][j];
	}

	printBoard(board);

	cout<<"\n\nNEW BOARD\n\n";

	if(sudoku_solver(board, 0, 0))
		printBoard(board);
	else
		cout << "No solution is possible for current setup" << endl;
}