#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void takeInput(int arr[], int n) {
	for(int i = 0;i<n;++i)
		cin >> arr[i];
}

int binSearch(int arr[], int beg, int end, int key) {
	if(beg > end)	return -1;

	int mid = (beg+end)/2;

	if(arr[mid] == key)
		return mid;
	if(arr[mid] < key)
		return binSearch(arr, mid+1, end, key);
	else
		return binSearch(arr, beg, mid -1, key);
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	takeInput(arr, n);

	int key;
	cin >> key;

	int i;
	for(i = 0; i<n-1; ++i)
		if(arr[i] > arr[i+1])
			break;

	if(key >= arr[0])
		cout<<(binSearch(arr, 0, i, key))<<endl;
	else
		cout<<(binSearch(arr, i+1, n-1, key))<<endl;
	
}