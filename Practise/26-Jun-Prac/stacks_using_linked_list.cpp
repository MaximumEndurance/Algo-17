#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
	Node(int val) {
		data = val;
		next = NULL;
	}
};


class stack : public Node {
	Node* n1;
	Node* head;
public:
	stack(int num) {
		n1 = NULL;
		n1 = new Node(num);
		head = n1;
	}

	void push_back(int val) {
		n1->next = new Node(val);

		n1 = n1->next;
	}

	int pop() {
		int temp = head->data;
		head = head->next;

		return temp;
	}

	int top() {
		return head->data;
	}

	bool isEmpty() {
		if(head == NULL)
			return true;
		else
			return false;
	}

	void print() {
		Node* temp = head;
		while(temp != n1) {
			cout<<temp->data<<" "	;
			temp = temp->next;
		}
		cout<<temp->data<<endl;
		cout<<endl;
	}
};

int main() {
	stack s1(20);

	s1.print();

	cout<<s1.top()<<endl;

	s1.push_back(40);
	s1.push_back(-8);
	s1.push_back(90);

	cout<<s1.pop()<<endl;

	s1.print();
}