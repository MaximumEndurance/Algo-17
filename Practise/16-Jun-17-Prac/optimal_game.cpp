#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5;
int score1, score2;
int optimal_result(int arr[N], int beg, int end) {
	//I choose beg

	if(beg >= end)	return 0;
	 score1 = min(arr[beg]+optimal_result(arr, beg+2, end), arr[beg]+optimal_result(arr, beg+1, end-1));	//whenever you get a zero, always rememeber ki tum base case mein kuch bhi nahi ar rahe ho.
	 score2 = min(arr[end]+optimal_result(arr, beg, end-2), arr[end]+optimal_result(arr, beg+1, end-1));	//kyunki vo to chahega hi ki you score less.

	

	return max(score1, score2);
}

int main() {
	int arr[N] = {3, 8, 9 ,15, 16};

if(score1 > score2)
		cout<<"Start from beginning"<<endl;
	else
		cout<<"Start from end"<<endl;
	cout<<"Max score possible is: "<<optimal_result(arr, 0 , N-1)<<endl;
}