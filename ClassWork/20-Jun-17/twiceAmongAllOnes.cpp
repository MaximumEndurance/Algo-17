#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//constatn space complexity
int main() {
	int n;
	cin >> n;
	int arr[n];
	int no[32] = {};

	for(int i = 0;i<n; ++i)
		cin >> arr[i];

	int final_xor = 0;

	for(int i =0;i<n;++i) {
		final_xor = final_xor ^ arr[i];
	}

	int temp =final_xor, count =0;
	while(temp){
		if(temp & 1){
			break;
		}
		else
			++count;
	}

	int divideBy = int(pow(2, count));


	int arr1[n] = {};
	int arr2[n] = {};
	int arr1_count=0, arr2_count=0;

	for(int i=0;i<n;++i) {
		if(arr[i]%divideBy)
			arr1[arr1_count++] =a[i];
		else
			arr2[arr2_count++] = a[i];
	}

	int xor1 = 0, xor2;

	// ince i dont need the os dont store them in an array
	for(int i =0 ;i<arr1_count;++i){
		xor1 = xor1 ^ arr1[i];
	}

	for(int i =0 ;i<arr2_count;++i){
		xor2 = xor2 ^ arr2[i];
	}

	cout <<xor2<<' '<<xor1<<endl;
	
}