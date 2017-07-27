#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
public:
	int data;
	Node * next;	//self referential class
	
	Node(int num){
		data = num;
		next = NULL;	//NULL is a macro
	}
};

void addToFront(Node* &head, Node* nodeToAdd){
	if (head == NULL){
		head = nodeToAdd;
		return;
	}

	nodeToAdd->next = head;
	head = nodeToAdd;
}


Node* takeInput(int n){
	//take n numbers and add each successive number to the front of LL
	Node * head = NULL;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		Node * newNode = new Node(num);
		addToFront(head, newNode);
	}
	return head;
}

void print(Node* head){
	//prints the Linked list
	Node * tmp = head;
	while(tmp != NULL){
		//I have not reached the end
		cout << tmp->data << "-->";
		tmp = tmp->next;
	}
	cout << endl;
}

Node* midpoint(Node * head) {
	Node * slow = head;
	Node * fast = head;

	while(fast->next && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main() {
	int n;
	cin >> n;
	Node* head= takeInput(n);
	print(head);
	Node * ans = midpoint(head);
	cout<<(ans-> data)<<endl;
}