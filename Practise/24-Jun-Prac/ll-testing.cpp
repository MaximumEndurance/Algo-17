#include <iostream>

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

void print(Node * head) {
	while(head != NULL) {
		cout<<(head->data)<<"->";
		head = head->next;
	}

	cout<<endl;
}

Node * insert() {
	int n = 0;
	
	Node* temp = NULL;
	Node* head = NULL;

	while(cin >> n && n!=-1) {
			Node* newNode = new Node(n);

		if(head == NULL) {
			head = newNode;
			temp = newNode;
			continue;
		}

		temp->next = newNode;
		temp = newNode;
	}
	return head;
}

int length(Node* head, int count = 0) {
	
	if(head==NULL)
		return count;

	return length(head->next, count+1);
}

int main() {
	Node* head = insert();
	print(head);
	cout<<length(head)<<endl;
}