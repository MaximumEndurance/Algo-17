#include "ll.h"

Node* doesCycleExist(Node* head) {
	Node* slow = head;

	if(head == NULL)
		return slow;
	
	Node* fast = head->next;

	while(slow!=fast) {
		if(fast == NULL || fast->next==NULL) {
			return NULL;
		}

		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;
}

void removeCycle(	Node* head) {

	Node* intersection = doesCycleExist(head);
	Node* temp = head;

	while(temp!=intersection) {
		cout<<"in"<<endl;

		temp = temp->next;
		intersection = intersection->next;
	}
	temp->next = NULL;

}

void createCycle(Node* head) {
		//creating a cycle
	Node* temp = head;

	while(temp && temp->next != NULL) {
		temp = temp->next;
	}

	Node* initialend = temp;
	temp->next = new Node(99);
	temp->next->next = new Node(100);
	temp->next->next->next = initialend;

	//cycle created
}

int main() {
	Node* head = insert();

	//cout<<doesCycleExist(head)<<endl;


	createCycle(head);

	//cout<<doesCycleExist(head)<<endl;

	removeCycle(head);

	print(head);
}
