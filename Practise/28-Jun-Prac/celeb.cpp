#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int n = 4;
const int a[][n] = { {0, 0, 0, 0},
					 {0, 1, 0, 1},
					 {1, 0, 1, 1},
					 {1, 1, 1, 1} };


bool knows(int i, int j) {
	return a[4-i+1][4-j+1];
}

int celeb(stack<int>& s) {
	int first, second;
	while(!s.empty()) {

		first = s.top();
		s.pop();

		if(s.empty()) {
			return first;
		}

		second = s.top();

		if(knows(second, first)) {
			s.pop();
			s.push(first);
		}
	}
}
int main() {

	stack<int> s;
	int temp =n;
	while(temp--) {
	int val;
	cin >> val;
	s.push(val);

	}

	cout<<celeb(s)<<endl;


}