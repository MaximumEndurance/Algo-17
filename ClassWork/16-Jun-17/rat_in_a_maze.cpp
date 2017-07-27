#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

const int n = 4;

void print(bool board[n][n]){
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool maze(bool board[n][n], int row, int col) {
	//if(row == reqd_row && col == reqd_col) {
	//	cout << path <<endl;
	//	return true;
	//}
/*
	if(row >=n && col>=n)
		return false;
*/
	if(row>=n || col >=n){	// ni ho sakta

		return false;
	}

	if(row==n-1 && col==n-1) {		//agar last tak pahucha tabhi print karo
		board[row][col] = 1;
		print(board);
	}

	if(board[row][col] == 0) {
		board[row][col] = 1;

		if( (row<n && maze(board, row+1, col)) || (col<n && maze(board, row, col+1)) )
			return true;

		board[row][col] = 0;	//reset cell and backtrack
		return false;
	}
}

int main() {
	freopen("rat_in_a_maze.in", "r", stdin);
	int board[n][n];

	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j)
			cin >> board[i][j];
	}

}