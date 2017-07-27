#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* random;

	Node(int data) {
		this->data = data;
	}
	};


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

Node* simplecopy(Node* head1, Node* head2, map<Node*, Node*>& M) {
	if(!head1 || !head2)	return NULL;
	Node* temp;
	// temp = head1;
	head2 = new Node(head1->data);
	M[head1] = head2;
	head1 = head1->next;

	while(!head1) {
		temp = new Node(head1->data);
		M[temp] = head2;
		head1 = head1->next;
		temp = temp->next;
	}
	return head2;
}

void setRandomIN2(map<Node*, Node*>& M) {
	for(map<Node*, Node*>::iterator ii = M.begin(); ii!=M.end(); ++ii) {
		(*ii.second)->random = M[(*ii).first->random]
	}
}

void setRandom(Node* head, map<Node*, Node*>& M) {
	vector<Node*> v;
	Node* temp = head;
	while(temp) {
		v.push_back(temp);
		temp = temp->next;
	}

	random_shuffle(v.begin(), v.end());

	tmp = head;
	int i =0;
	while(temp) {
		temp->random = v[i++];
		temp = temp->next;
	}
	setRandomIN2(M);
}

void print(Node * head) {
	if(head == NULL) {
		return;
	}
	while(head->next != NULL) {
		cout<<(head->data)<<"("<<(head->random?head->random->data : -1)<<")->";
		head = head->next;
	}
	if(head)
		cout<<(head->data)<<"("<<((head->random)?(head->random->data) : -1)<<")->";
	cout<<endl;
}

int main() {
	map<Node*, Node*> M;

	Node* head1 = insert();
	setRandom(head1, M);

	Node* head2;
	const int y =14;

	head2 = simplecopy(head1, head2, M);

	print(head2);
}