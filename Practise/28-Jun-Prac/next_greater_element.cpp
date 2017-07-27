#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

std::vector<int> next_greater(int a[], int n) {

	stack<int> s;
	std::vector<int> vec;

	for(int i = n-1;i>=0;--i) {
		while(!s.empty() && (s.top() < a[i])) {
			s.pop();
		}

		if(s.empty()) {
			vec.push_back(-1);
		}
		else {
			vec.push_back(s.top());
		}
		s.push(a[i]);
	}

	return vec;
}

void printHelp(int x) {
	cout<<x<<' ';
}

void print(std::vector<int>& vec) {
	for_each(vec.rbegin(), vec.rend(), printHelp);
	cout<<endl;
}

int main() {
	int n ;
	 cin >> n;
	 int a[n];

	 for(int i = 0;i<n; ++i) {
	 	cin  >> a[i];
	 }

	 std::vector<int> v = next_greater(a, n);

	 print(v);

}