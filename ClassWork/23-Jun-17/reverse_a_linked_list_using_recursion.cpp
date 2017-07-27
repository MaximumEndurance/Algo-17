#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.h"
using namespace std;

Node* reverse(Node* head) {

	if(head->next == NULL) return head;

	Node* newHead = reverse(head->next);

	head->next->next = head;
	head->next = NULL;

	return newHead;
}

int main() {
	int n;
	cin >> n;
	Node * head = takeInput(n);
	print(head);
	Node * reversed = reverse(head);
	print(reversed);	
}