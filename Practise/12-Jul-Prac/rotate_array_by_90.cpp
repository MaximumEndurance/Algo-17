#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 4;

enum choice{input, display};

void io(int arr[N][N], choice ch) {

	for(int i =0;i<N;++i) {
		for(int j=0;j<N;++j) {
			if(ch == input) {
			cin >> arr[i][j];
		}
		else if(ch==display) {
			cout<<arr[i][j]<<' ';
		}
		}
		if(ch == display)
		cout<<endl;
	}

}
void rotate(int arr[][4], int x, int y) {

	if(x==N)	return;

	for(int y = x;y<=N-x-1; ++y) {
		int temp = arr[y][N-1-x];

		arr[y][N-1-x] = arr[x][y];

		int temp2 = arr[N-1-x][N-1-y];
		arr[N-1-x][N-1-y] = temp;

		temp2 = arr[N-1-y][x];

		arr[N-1-y][x] = temp;

		temp2 = arr[x][y];
		arr[x][y] = temp;

		rotate(arr, x+1, x); 
	}
}

int main() {
	int arr[N][N];

	io(arr, input);
	rotate(arr, 0, 0);

	io(arr, display);
}