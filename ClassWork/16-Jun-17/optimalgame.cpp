#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int n =4;

int soln(int arr[n], int beg, int end) {
	if(beg>=end) return 0;

	int ch1 = arr[beg] + soln(arr, beg+2, end);
	int ch2 = arr[beg] + soln(arr, beg+1, end-1);

	int score1 = min(ch1, ch2);

	int ch3 = arr[end] + soln(arr, beg, end-2);
	int ch4 = arr[end] + soln(arr, beg+1, end-1);

		int score2 = min(ch3, ch4);

		return max(score1, score2);

}

int main() {
	int arr[n] = {5, 6, 14, 3};

	cout<< soln(arr, 0, n-1) <<endl;

}