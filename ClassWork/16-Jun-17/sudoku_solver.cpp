#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int n = 9;

bool canPlace(int board[n][n], int row, int col ,int num) {
	if(board[row][col])
}

bool sudukoSolver(int board[n][n], int row, int col) {

	if(x>=N)	return true;	//Ho gaya solve	

	if(y>=N){
		//row ho gayi puri

		return sudukoSolver(board, row+1, 0);
	}

	if(board[row][col]){
		return sudokuSolver(board, row, col+1);
	}

	for(int i =1;i<=n ;++i) {
		if(canPlace(board, row, col, i)){
			board[row][col] = i;

			if(sudukoSolver(board, row, col+1));	//row wise bhar rahe hain... aage bad jao.
		}
		board[row][col] = 0;	//reset kardo. Ni bhar paaye.
	}
	return false;
}

int main() {
	
}