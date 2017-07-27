#include "generic-tree.h"

queue<Node*> modifyLevel(queue<Node*> q, int level) {
	if(q.empty()) return q;

	queue<Node*> q2;

	while(!q.empty()) {

		Node* currNode = q.front();
		currNode->data = level;
		q2.push(currNode);
		q.pop();
		}
		return q2;
}

void calcLevel(Node* root, int level=0) {
	if(!root) return;

	queue<Node*> q;
	root->data =0;
	q.push(root);
	q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

		if(currNode == NULL) {
			++level;
			q = modifyLevel(q, level);
			
			if(!q.empty()) {
				q.push(NULL);
			}
			continue;
		}
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);
		}
	}

}

void printEndL(queue<Node*> q) {
	// cout<<"inside"<< q.size()<<endl;
	if(q.empty())	return;	
	if(q.front() == NULL) {
		cout<<"NULL ";
	}
	else {
	cout<<(q.front()->data)<<' ';
}
	q.pop();
	printEndL(q);	
}



void printEnd(Node* root) {
	if(!root) return;

	queue<Node*> q;
	queue<Node*> totalQ;

	q.push(root);
	q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		totalQ.push(currNode);
		q.pop();

		if(currNode == NULL) {
			cout<<endl;
			//printWithEnd(prevQ, q);

			if(!q.empty()) {
				q.push(NULL);
				totalQ.push(NULL);
			}
			continue;
		}

	
 	cout<<currNode->data<<' ';
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);
		totalQ.push(*ii);

	}
	}
	printEndL(totalQ);
	// cout<<"Size "<<totalQ.size()<<endl;
}

int main() {
	Node* root = takeInput();
	calcLevel(root);
	printEnd(root);

}
