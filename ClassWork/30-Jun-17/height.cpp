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

Node * takeInputLevel(){
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		// cout<<"in"<<endl;
		//there is a node with potential to become parent
		Node *curParent = q.front();
		q.pop();

		int leftData;	cin >> leftData;
		//left child exists, hence create and attach to the parent
		//Also, this child can become Parent in the near future ;)
		if (leftData != -1){
			Node * tmp = new Node(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		//similarly for right child
		int rightData; 	cin >> rightData;
		if(rightData != -1){
			Node * tmp = new Node(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}

void printLevel(Node* root) {
	if(root == NULL)	return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()) {
		printLevel(root->left);
	}  
}

int height(Node* root) {
	//cout<<"in"<<endl;
	if(!root) return 0;
	return 1+max(height(root->left), height(root->right));

}

int main() {
	Node* root = takeInputLevel();
	//printLevel(root);
	cout<<height(root)<<endl;
}