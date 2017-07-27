#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;

void print() {
	while(!q1.empty()) {
		cout<<q1.front()<<' ';
		q1.pop();
	}
	cout<<endl;
}

void push(int val) {
	if(q1.empty()) {
		q1.push(val);
	}

	else {
		while(!q1.empty()) {
			int elem = q1.front();

			q2.push(elem);
			q1.pop();
		}

		q1.push(val);

		while(!q2.empty()) {
			int elem = q2.front();

			q1.push(elem);
			q2.pop();

		}
	}

}


int pop() {
	if(q1.empty()) {
		return -1;
	}

	int elem = q1.front();
	q1.pop();
	return elem;
}



int main() {
	int num;
	while(cin >> num && num != -1){
		push(num);
	}

	int ch;
	print();
// 	cout<<pop()<<endl;
// 	cout<<pop()<<endl;
// 	print();
}