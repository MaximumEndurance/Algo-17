#include <iostream>
#include <stack>

using namespace std;

const int width = 1;

int area(int arr[], int n) {
	if(n ==0 )	return -1;

	stack<int> s;

	s.push(0);
	int maxarea = 0;
	for(int i =1; i<n; ++i) {
		if(arr[s.top()] > arr[i]) {
			if((i-s.top())*width > maxarea) {
				maxarea = (i-s.top())*width;
				s.pop();
				s.push(i);
			} 
		}
	}
	return maxarea;
}

int main() {
	int n;
	cin >> n;

	int a[n];

	for(int i =0;i<n ;++i) {
		cin >> a[i];
	}

	cout<<area(a, n)<<endl;
}