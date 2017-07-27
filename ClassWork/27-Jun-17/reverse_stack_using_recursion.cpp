#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void addToBottom(stack<int>& s, int val) {
	if(s.empty() == true) {
		s.push(val);
		return;
	}

	int curr = s.top();

	s.pop();

	addToBottom(s, curr);

	s.push(curr);
}

void reverse(stack<int>& s) {

	if(s.empty() == true) {
		return;
	}

	int curr = s.top();
	s.pop();
	reverse(s);

	addToBottom(s, curr);
}

void print(stack<int>& s) {
	while(!s.empty()) {
		cout<<s.top()<<' ';
		s.pop();
	}
	cout<<endl;
}

int main() {
	stack<int> s;
	int n;
	while(cin >> n && n!= -1) {
		s.push(n);
	}

	reverse(s);

	print(s);

}