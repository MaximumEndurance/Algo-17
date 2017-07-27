#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int n = 4;

void printBoard(bool board[n][n]) {
	for(int i=0; i<n; ++i){
		for(int j=0;j<n; ++j)
			cout<<board[i][j]<<' ';

		cout<<endl;
	}
}

bool check(bool board[n][n], int r, int c) {
	int i, j;

	for(i=0;i<=c;++i)
		if(board[r][i])	return false;
	

	for(i=0;i<=r;++i)
		if(board[i][c])	return false;

	for(i=r-1, j=c-1; j>=0 && i>=0;--i, --j)
		if(board[i][j])		return false;
	

	for(i=r+1, j=c+1; i<=n && j<=n; ++i, ++j)
		if(board[i][j])	return false;

	return true;
}

bool queen(bool board[n][n], int col){
	if(col >= n)	return true;

	 
		for(int j=0; j<n; ++j){
			if(check(board, j, col)){
				board[j][col] = 1;

				if(queen(board, col+1))
					return true;

				board[j][col] = 0;

			}
		}
		return false;
	}

int main() {

	 bool board[n][n]= {};	

	if(queen(board, 0)) {
	printBoard(board);
	}
	else{
		cout<<"No soln exists"<<endl;
	}

}