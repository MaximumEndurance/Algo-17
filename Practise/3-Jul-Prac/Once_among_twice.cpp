#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int find_no_occuring_once(int a[], int n, int beg = 0) {
	if(beg == n-1){
		return a[beg];
	}
	return (a[beg] ^ find_no_occuring_once(a, n , beg+1)); 
}

int main() {
	int n;
	cin >> n;
	int a[n], i;
	int temp = 0;
	
	while(temp!=n) {
		cin >> a[temp++];
	}
	if(n%2==0) {
		return 0;
	}
	cout<<find_no_occuring_once(a, n)<<endl;
}