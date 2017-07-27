#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int cheese_row, cheese_col;

const int N = 5;

void printBoard(char board[N][N]){
	for(int i =0 ;i<N;++i)	{
		for(int j=0;j<N;++j)
			cout<<board[i][j]<<' ';
		cout<<endl;
	}
}

char maze(char board[N][N], int row, int col) {
	if(row == cheese_row && col == cheese_col) {
		printBoard(board);
		return true;
	}

	if(row>=N && col>=N)
		return false;

	if(board[row][col] == '0') {
		cout << "yes"<<endl;
		board[row][col] = '1';

		if(maze(board, row+1, col) || maze(board, row, col+1))
			return true;

		board[row][col] = '0';
	
	return false;
	}
}

int main() {
	freopen("rat_in_a_maze.in", "r", stdin);

	char board[N][N];

	cheese_row = N-1;
	cheese_col = N-1;

	for(int i =0 ;i<N;++i)	{
		for(int j=0;j<N;++j)
			cin >> board[i][j];
	}
	printBoard(board);
	cout<<"\n\nNewBoard\n\n";
	maze(board, 0, 0);

}