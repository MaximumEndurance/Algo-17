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

void input(Node* &root) {
    
    int data;
     cin >> data;
     root = new Node(data);
     //cout<<root->data<<endl;
     
     bool hasALeftChild, hasARightChild;
     string leftInput, rightInput;
     
     cin >> leftInput;
     
     hasALeftChild = (leftInput == "true") ? 1 : 0;
     
     if(hasALeftChild) {
         input(root->left);
     }
     
     cin >> rightInput;
     hasARightChild = (rightInput == "true") ? 1 : 0;

     
     if(hasARightChild) {
         input(root->right);
     }

     return;
}

Node* takeInput() {
    int data;
    cin >> data;
    
    if(data == -1)	return NULL;

    Node* root = new Node(data);
    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {
    	Node* currNode = q.front();
    	q.pop();
    	int leftData;
    	cin >> leftData;
    	if(leftData!=-1) {
    		Node* newNode = new Node(leftData);
    		currNode->left = newNode;
    		q.push(currNode->left);
    	}

    	int rightData;
    	cin >> rightData;
    	if(rightData!=-1) {
    		Node* newNode = new Node(rightData);
    		currNode->right = newNode;
    		q.push(currNode->right);
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
void InOrder(Node* root) {
	if(!root) return;

	if(root->left == NULL && root->right==NULL)
		cout<<root->data<<' ';

	InOrder(root->left);
	InOrder(root->right);
}

int main() {
    Node* root = takeInput();
    Node* root = NULL;
    input(root);
    InOrder(root);
}
