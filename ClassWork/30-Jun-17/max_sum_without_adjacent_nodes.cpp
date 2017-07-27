#include "tree.h"
#include <stack>

void printVec(std::vector<Node*> v) {
	for(std::vector<Node*>::iterator i =v.begin(); i!= v.end(); ++i) {
		cout<<(*i)<<"-->";
	}
	cout<<endl;
}

void printStack(stack<Node*> s) {
	if(s.empty()) {
		cout<<endl;
		return;
	}

	cout<<((s.top())->data)<<"-->";
	s.pop();
	printStack(s);
}

stack<Node*> s;

void allPaths(Node* root) {
	//Prints all possible paths from root to all leaf nodes
	//vector<Node*> vec;

	if(!root)	return;
	if(root->left == NULL && root->right == NULL) {
		//printVec(vec);
		s.push(root);
		printStack(s);
		s.pop();
		return;
	}

	//vec.push_back(root);
	//s.push(root);

	allPaths(root->left);
	allPaths(root->right);
	// s.pop();
}

int main() {
	Node* root = takeInput();
	allPaths(root);
}