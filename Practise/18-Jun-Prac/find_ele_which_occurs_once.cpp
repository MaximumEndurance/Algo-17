#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//best logic ever
int xor_arr(int a[], int n){
	int xor_sum= a[0] ;

	for(int i = 0;i<n-1;++i)
		xor_sum = xor_sum ^ a[i+1];

	return xor_sum;
}

int main() {
	int arr[] = {2, 3, 3, 1 , 1 , 4, 4 };
	cout<<xor_arr(arr, sizeof(arr)/sizeof(int));
}