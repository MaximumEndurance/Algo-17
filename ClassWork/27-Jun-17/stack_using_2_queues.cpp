#include <iostream>
#include <queue>

using namespace std;



	queue<int> q1;

	queue<int> q2;



void print() {
	int count	 = 0;
	while(count < q1.size()) {
		cout<<q1.front();
		q1.pop();
		++count;
	}
}

void push_back(int val) {


	while(!q1.empty()) {
	q2.push(q1.front());
	q1.pop();
	}

	q1.push(val);

	while(!q2.empty()) {
		q1.push(q2.front());
		q2.pop();
		}
		print();
	}

int pop() {
		if(!q1.empty()) {
			int elem = q1.front();
			q1.pop();
			return elem;

		}

		else {
		int elem = q2.front();
		q2.pop();
		return elem;
	}
	
}



int main() {



	push_back(2);

	 push_back(4);

	pop();
	print();

	push_back(6);

	push_back(8);

	pop();
	print();
}