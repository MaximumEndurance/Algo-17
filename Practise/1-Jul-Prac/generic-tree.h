#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	vector<Node*> vec;

	Node(int val) {
		data = val;
	}
};

Node* takeInput() {
	int data;
	cin >> data;

	Node* root = new Node(data);
	int children;
	cin >> children;

	while(children--) {
		Node* newNode = takeInput();
		root->vec.push_back(newNode);
	}
	return root;
}


void print(Node* root) {
	if(!root) return;

	queue<Node*> q;

	q.push(root);
	q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

		if(currNode == NULL) {
			cout<<endl;
			if(!q.empty()) {
				q.push(NULL);
			}
			continue;
		}

	
 	cout<<currNode->data<<' ';
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);

	}
	}
}