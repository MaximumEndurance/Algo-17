#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.h"

using namespace std;


Node* midpoint(Node * head) {
	Node * slow = head;
	Node * fast = head;

	while(fast->next !=NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* reverse(Node* head) {
	Node* curr = head;
	Node* ahead = NULL;
	if(head->next)
	ahead = head->next;

	if(	ahead != NULL) {
		Node* temp = ahead->next;
		ahead = curr;
		curr = temp;
	} 
	return curr;
}

int main() {
	int n;
	cin >> n;
	Node* head= takeInput(n);
	print(head);
	reverse(head);
	print(head);
	//Node * ans = midpoint(head);
	//cout<<(ans-> data)<<endl;
}