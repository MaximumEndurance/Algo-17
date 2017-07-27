#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>


//chalta hai sahi se.
using namespace std;

const int M =4, N=5;
void printBoard(char board[M][N]) {
	for(int i =0;i<M;++i) {
		for(int j=0;j<N;++j)
			cout<<board[i][j]<<' ';

		cout<<endl;
	}
	cout<<"\n\n\n";
}


bool maze(char board[M][N], int row, int col) {

	if(row >= M && col >= N) {
		return false;
	}

	if(row == M-1 && col == N-1) {
		board[row][col] = '1';
		printBoard(board);
	}

	if(board[row][col] == '0') {
		board[row][col] = '1';

		if(row < M-1 && maze(board, row+1, col))
			return true;
		if(col < N-1 && maze(board, row, col+1))
			return true;

	board[row][col] = '0';
	return false;
	}
	return false;
}

void takeInput(char board[M][N], int M, int N) {
	for(int i = 0;i<M;++i)
		for(int j = 0;j<N;++j)
			cin >> board[i][j];
}


int main() {
	freopen("rat_in_a_maze.in", "r", stdin);
	char board[M][N];
	takeInput(board, M,N);
    maze(board, 0 , 0);
}