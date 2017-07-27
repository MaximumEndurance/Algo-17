#include "tree.h"

int sum_of_nodes(Node* root, int sum = 0) {
	if(!root) return 0;

	queue<Node*> q;

	q.push(root);
	//q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

		// if(currNode == NULL) {
		// 	cout<<endl;
		// 	if(!q.empty()) {
		// 		q.push(NULL);
		// 	}
		// 	continue;
		// }

	
 	cout<<currNode->data<<' ';
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		sum += (*ii)->data;
		q.push(*ii);

	}
	}
	return sum;
}

int main() {
	Node* root = takeInput();
	cout<<sum_of_nodes(root)<<endl;
}