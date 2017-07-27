#include "ll.h"


// Lst node cannot de deleted using this
void delete_K_node(Node* key) {
	Node* temp = key;

	if(temp == NULL)
		return;
	if(temp->next == NULL) {	//ek hi node bheji
		temp = NULL;
		return; 
	}

	while(temp->next->next!= NULL){
		temp->data = temp->next->data;
		temp = temp->next;
	}
	temp->data = temp->next->data;
	temp->next = NULL;
}

int main() {
	Node* head = insert();
	int k;
	//cout<<"Enter kth node to delete ";
	cin >> k;

	print(head);
	Node* temp = head;

	if(temp == NULL)
		return 0;
	
	while(--k && temp!= NULL) {
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	delete_K_node(temp);
	print(head);	
}