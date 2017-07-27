#include "ll.h"

bool detectCycle(Node* p1, Node* p2, int jump = 2) {
	int iteration = 1; 
	static Node* head = p1;

	cout<<head->data<<endl;

	if(p2 == NULL) {
		cout<<"No cycle exists"<<endl;
		return false;
	}

	int initialdata= p2->data;

	while(p2->data != p1->data) {
		
		if(iteration%jump == 0 && p2->data==initialdata){
			break;
		}
		else{
			initialdata = p2->data;
		}

		cout<<p2->data<<' '<<head->data<<endl;
		cout<<"in"<<endl;
		if(p1->data == p2->data) {
		p2->next = NULL;
		return true;
	}

		p2 = p2->next;

		p1 = p1->next;

		++iteration;
	}

	return false;
}

void calling_detect_cycle(Node* head) {
	Node* end = NULL;

	if(head && head->next) {
		end = head->next->next;
	}
	
	if(head->data == end->data) {
		return;
	}
	static int jump =1;

	if(!detectCycle(head, end)) {
		detectCycle(head, end->next, jump+1);
	}
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

	createCycle(head);
	//print(head);
	calling_detect_cycle(head);
	// print(head);
}