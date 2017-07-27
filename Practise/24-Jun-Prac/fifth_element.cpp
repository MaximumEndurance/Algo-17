#include "ll.h"

Node* fifth_ele(Node* head) {

	Node* temp = head;
	int count = 5;

	while(count && temp) {
		count--;
		temp = temp->next;
	}

	if(count != 0 )	{
		cout<<"No fifth node exists for the current setup"<<endl;
		return NULL;
	}

	else{ 
		if(count == 0 && temp == NULL)
		return head;
	else
	return fifth_ele(head->next);
	}
}

int main() {
	Node* head = insert();
	print(head);

	Node* ans = fifth_ele(head);

	if(ans!=NULL)
		cout<<ans->data<<endl;
}