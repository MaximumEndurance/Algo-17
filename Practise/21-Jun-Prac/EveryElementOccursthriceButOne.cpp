#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int BITS = 32;

void populateCountArr(int count_arr[], int no) {
	int c_index = 0;

	while(no){
		if(no & 1 == 1)
			count_arr[c_index]++;

		c_index++;
		no/=2;

	}
}

int main() {
	int count_arr[BITS] = {};
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n; ++i)
		cin >> arr[i];

	for(int i =0;i<n;++i) {
		populateCountArr(count_arr, arr[i]);
	}

	int sum = 0;
	for(int i =0;i<	BITS;++i) {
		if(count_arr[i] % 3 == 1)
			sum += 1<<i;
	}

	cout<<sum<<endl;
}