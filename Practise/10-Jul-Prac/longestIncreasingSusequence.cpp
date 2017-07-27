#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int arr[1000];

	int n, i=0;
	while(cin >> n && n!=-1) {
		arr[i++] = n;
	}
	int beg =0, end=0;
	int fast=0;
	for(int j=0;j<i;) {
		fast = j+1;
		while((fast < i) && (arr[fast] > arr[j])) {
			++fast;
		}
		if((fast-j) > (end-beg)) {
			end = fast;
			beg = j;
		}
		j=fast;
	}

	for(int i =beg ;i<end;++i) {
		cout<<arr[i]<<' ';
	}
}