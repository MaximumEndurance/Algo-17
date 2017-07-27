#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node* takeInput() {
	queue<Node*> q;

	int data;
	cin >> data;
	Node* root = new Node(data);

	q.push(root);

	while(!q.empty()) {

		Node* currNode = q.front();
		int leftData;
		cin >> leftData;

		if(leftData != -1) {
			currNode->left = new Node(leftData);
			q.push(currNode->left);
		}

		int rightData;
		cin >> rightData;

		if(rightData != -1) {
			currNode->right = new Node(rightData);
			q.push(currNode->right);
		}
		q.pop();
	}
	return root;
}

void printNormal(Node* root) {

	if(!root) {
		return;
	}

	printNormal(root->left);
	cout<<root->data<<endl;
	printNormal(root->right);
}

void print(Node* root) {
	
	if(root) {
	cout<<(root->data)<<endl;
	}
	else{
		return;
	}

	queue<Node*> q;

	q.push(root);

	while(!q.empty()) {

		Node* currNode = q.front();
		cout<<currNode->data<<' ';

		if(currNode == NULL) {
			cout<<endl;

			if(!q.empty()) {
				q.push(NULL);
			}
		}
		if(currNode->left) {
			q.push(currNode->left);
		}
		else{
			cout<<"-1 "<<' ';
		}

		if(currNode->right) {
			q.push(currNode->right);
			}
		else {
			cout<<"-1 "<<' ';
		}

		q.pop();
	}

}


int count(Node* root) {
	if(!root) return 0;

	return (1 + count(root->left) + count(root->right));
}

void InOrder(Node* root) {
	if(!root) return;
		cout<<root->data<<' ';

	InOrder(root->left);
	InOrder(root->right);
}

void PostOrder(Node* root) {

	if(!root) return;

	PostOrder(root->left);
		cout<<root->data<<' ';

	PostOrder(root->right);

}

void PreOrder(Node* root) {

	if(!root) return;


	PreOrder(root->left);
	PreOrder(root->right);
		cout<<root->data<<' ';

}

int main() {
	Node* root = takeInput();
	// printNormal(root);
	InOrder(root);
	cout<<endl;
	PreOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;

	cout<<endl<<endl;	

	print(root);
}