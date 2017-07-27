#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int INF  = (1e5);

int change(int arr[], int sum, int *memopad) {

	int n = 4;

	if(sum == 0)	return 0;

	if(sum < 0)	return INF;

	if(memopad[sum] != -1)	return memopad[sum];	//value already computed hai
	int res = INF;

	for(int i = 0; i<n; ++i) {
		int rem = change(arr, sum - arr[i], memopad);
		int curAns = rem +1;	//curr coin bhi to utha liya hai
		res = min( curAns, res);
	}

	return 	memopad[sum] = res;

}

int n = 4;

int newChange(int arr[], int sum, int* memopad) {
	if(sum = 0)	return 0;
}

int main() {
	int arr[]= {1, 2, 5, 10};
	int sum;
	cin >> sum;
	int *memopad = new int[sum];

	memset(memopad, -1, 4 * (sum + 1));

	cout<<change(arr, sum, memopad)<<endl;
	delete [] memopad;
}