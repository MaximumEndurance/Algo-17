#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};


void print(Node* head) {
	if(!head) {
		cout<<endl;
	return;
}

	cout<<head->data<<' ';
	print(head->next);
}


Node* bubble_sort(Node* head, int n) {
	//cout<<'1'<<endl;
	if(!head || n < 1) {
		return head;
	}
	Node* prev = NULL;
	Node* curr = head;
	Node* ahead = head->next;
	if(curr->data > ahead->data) {
		head = ahead;
	}
	
	n -= 1;
	//cout<<'2'<<endl;
	//Node* temp =head;
	while(n-- && ahead) {
		//cout<<"in"<<endl;
		cout<<"\ncurr"<<curr->data <<' '<< ahead->data<<endl;
		if(curr->data > ahead->data) {
			prev = ahead;
			curr->next = ahead->next;
			ahead = curr;
		}
		else {
			prev = curr;
			curr = ahead;
			ahead = ahead->next;
		}
			print(head);

	}
	//cout<<'e'<<endl;
	return bubble_sort(head, n-1);
}

Node* input(int n) {
	if(n==0)	return NULL;

	int data;
	cin >> data;
	Node* head = new Node(data);
	head->next = input(n-1);
}

int main() {
		int n;
		cin >> n;
		Node* head= input(n);

		head = bubble_sort(head, n);
		print(head);

}