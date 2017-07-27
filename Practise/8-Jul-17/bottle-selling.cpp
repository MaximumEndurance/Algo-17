#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getMaxSum(int arr[], int beg, int end, int year) {

	if(beg > end) {
		return 0;
	}
	return (max(arr[beg]*year + getMaxSum(arr, beg+1, end, year+1), getMaxSum(arr, beg, end-1, year+1) + arr[end]*year ));
}

int ans2[100][100];
int getMaxSum2(int arr[], int beg, int end, int year) {
	
	if(beg > end) {
		return 0;
	}

	if(ans2[beg][end] != -1) {
		cout<<"yes"<<endl;	
		return ans2[beg][end];
	}

	ans2[beg][end] = (max(arr[beg]*year + getMaxSum(arr, beg+1, end, year+1), getMaxSum(arr, beg, end-1, year+1) + arr[end]*year ));
	// int ansbeg = beg;
	// int ansend = end;

	return ans2[beg][end];
}

int main() {
	for(int i=0;i<100;++i) {
		for(int j=0;j<100; ++j) {
			ans2[i][j] = -1;
		}
	}

	int arr[]= {2, 3, 5, 1, 4};
	int n = sizeof(arr)/sizeof(int);
	cout<<getMaxSum2(arr, 0, n-1, 1)<<endl;

		for(int i=0;i<100;++i) {
			for(int j=0;j<100 &&ans2[i][j]!=-1; ++j) {
				cout<<ans2[i][j]<<endl;
		}
	}
}