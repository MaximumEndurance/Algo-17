#include <iostream>
using namespace std;

int N;
	int count  = 0;
bool board[10000][10000] ={};
void print(){
	for(int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout<<endl<<endl<<endl;
}

bool canPlace( int x, int y){
	//check col
	for(int r = 0; r < x; ++r){
		if (board[r][y] == 1){
			return false;
		}
	}

	//check left diag
	for(int r = x - 1, c = y - 1; r >= 0 && c >= 0; --r, --c){
		if (board[r][c] == 1)	return false;
	}

	//check right diag
	for(int r = x - 1, c = y + 1; r >= 0 && c < N; --r, ++c){
		if (board[r][c] == 1) return false;
	}

	return true;
}


bool queen( int curRow){
	if (curRow >= N){
		return true;

	}

	for(int c = 0; c < N; ++c) {
		if (canPlace( curRow, c) == true){
			//looks promising
			board[curRow][c] = 1;

			if (queen(curRow + 1) == true){
				//I have a found a sol
				//++count;
				queen(curRow+1);
				return true;		
			}
			board[curRow][c] = 0; 	//backtracking---resetting the state
			//otherwise place the queen in next col of the same row
		}
	}
	return false;
}

int main(){
	cin >> N;

	for(int i =0;i<N/2;++i){

	bool solExist = queen(i);
	
	if (solExist == false){
		//not possible to place queens
		//cout << "Not possible with the setup\n";
	}
	else {
		++count;
		//print();
	}
}
cout<<count<<endl;
}