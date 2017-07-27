#include <iostream>
#include <algorithm>
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

Node* takeInputDFS() {
	int data;
	cin >> data;

	if(data == -1) {
		return NULL;
	}

	else{
		Node* root = new Node(data);
		root->left = takeInputDFS();
		root->right = takeInputDFS();
	}
}

Node* takeInputBFS() {
	int data;
	cin >> data;

	if(data == -1){
		return NULL;
	}

	Node* root = new Node(data);

	queue<Node*> q1;

	q1.push(root);

	while(!q1.empty()) {
		// Koi node papa banane layak hai
		int leftData;
		cin >> leftData;

		Node* currParent = q1.front();

		if(leftData != -1) {
			Node* temp =new Node(leftData);
			q1.push(temp);
			currParent->left = temp;
		}

		int rightData;

		if(rightData != -1) {
			Node* temp =new Node(rightData);

			q1.push(temp);
			currParent->right = temp;
		}
		q1.pop();
	} 
} 

void print(Node* root) {
	if(root== NULL) {
		return;
	}
	cout<<root->data<<' ';

	print(root->left);
	print(root->right);
}

void printBFS(Node* root) {
	queue<Node*> q1;

	q1.push(root);

	while(!q1.empty()) {
		Node* curr = q1.front();

		if(curr == NULL) {
			cout<<endl;
			if(!q1.empty()) {
					q1.push(NULL);
		}
		continue;
		}
		q1.pop();
		cout<< (curr->data) <<endl;

		if(curr->left)
		q1.push(root->left);

		if(curr->right)
		q1.push(root->right);
}

}

void InOrder(Node* root) {
	if(root== NULL) {

	return;
	}

	InOrder(root->left);
	//cout<<root->data<<' ';
	cout<<root;
	InOrder(root->right);

}

void postOrder(Node* root) {
	if(root == NULL ){
		return;
	}

	postOrder(root->right);
	cout<<root->data<<endl;
	postOrder(root->left);
}

	ostream& operator<<(ostream& obj, Node* &n) {
		printBFS(n);
		return obj;
	}

	istream& operator>>(istream& obj, Node* n) {
		n = takeInputBFS();
		return obj;
	}


int sum_in_parent(Node* root) {
	
	if(root == NULL) {
		return 0;
	}
	
	int sum_to_send = root->data + sum_in_parent(root->left) + sum_in_parent(root->right);
	root->data = sum_in_parent(root->left) + sum_in_parent(root->right);
	return sum_to_send;


}

unsigned count_Nodes(Node* root, unsigned count = 0) {
	if(root == NULL) {
		return count;
	}

	count_Nodes(root->left, count+1);
	count_Nodes(root->right, count+1);

	return count;
}


int main() {
	Node* root;
	//Node* root = takeInputBFS();
	// print(root);
	// InOrder(root);	
	// postOrder(root);


	cin >> root;
	cout<<root;
	cout<<count_Nodes(root)<<endl;
}

