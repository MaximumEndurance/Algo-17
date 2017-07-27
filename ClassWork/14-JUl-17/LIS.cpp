#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int inf = 1e6;

int lis(int arr[], int en, int& endIndex) {
	if(en == 0) {
		endIndex = en;
	}

	int bestsoFar = -inf;

	for(int i =0;i<en ;++i) {
		int len = lis(arr, i, endIndex);

		if(arr[endIndex] < arr[en]) {
			len += 1;
		}
		bestsoFar = max(bestsoFar, len);
	}
	return bestsoFar;

}

int lis(int arr[], int n) {
	int dp[n];

		// memset(dp, 1, n*4);
	
for(int i =0;i<n;++i){
	dp[i] = 1;
}
	for(int i = 1; i<n; ++i) {
		for(int j=0;j<n;++j) {
			int currLen = dp[j];
			if(arr[j] < arr[i]) {
				currLen = dp[j] + 1;
			}
			dp[i] = max(currLen, dp[i]);
		}
	}
	return dp[n-1];
}

int main() {
	int arr[] = { -5, 2, -4, 3};

	int n = sizeof(arr)/sizeof(arr[0]);

	int endIndex = -1;

	int ans = lis(arr, n-1);
	cout<<ans<<endl;
	}