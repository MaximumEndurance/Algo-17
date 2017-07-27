#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void add(stack<int>& s, int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}

	int elem = s.top();
	s.pop();

	add(s, x);

	s.push(elem);
}

void reverse(stack<int>& s) {
	if(s.empty()) return;

	int elem = s.top();
	s.pop();

	reverse(s);

	add(s, elem);

	
}

void print(stack<int>& s) {
	while(!s.empty()) {
		cout<<s.top()<<' ';
		s.pop();
	}
	cout<<endl;
}

int main() {
	//Now
	int num;

	stack<int> s;
	//print(s);

	while(cin>>num && num!=-1) {
		s.push(num);
	}
	reverse(s);
	print(s);
}