#include "generic-tree.h"

// bool isFound = 0;
int justLarger(Node* root, int k) {
	if(!root) return -1;

	queue<Node*> q;

	q.push(root);
	//q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

	if(currNode->data > k) {
		return currNode->data;
	}
 	
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);

	}
	}
	return -1;	
}

int main() {
	Node* root = takeInput();
	int num;
	cin >> num;
	//print(root);
	cout<<justLarger(root, num)<<endl;
}

