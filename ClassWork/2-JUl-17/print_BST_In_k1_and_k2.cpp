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

void print(Node* root) {
    if(!root) return;
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if(currNode == NULL) {
            cout<<endl;
            //q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<currNode->data<<' ';
        
        if(currNode->left) q.push(currNode->left);  
        if(currNode->right) q.push(currNode->right);
    }

}

Node* insertInBST(Node* root, int num) {
	if(!root)	{
		root = new Node(num);
		return root;
	}

	if(root->data > num) {
		root->left=insertInBST(root->left, num);
	}
	else {
		root->right=insertInBST(root->right, num);
	}
	return root;
}

Node* takeInput() {
	int num;
	Node* root = NULL;
	while(cin >> num && num!=-1) {

	root= insertInBST(root, num);
	}
	return root;
}

void printbwK1AndK2(Node* root, int k1, int k2) {
	if(root == NULL) {
		return;
	}

	if(root->data >= k1 && root->data <= k2) {
		cout<<root->data<<' ';
		printbwK1AndK2(root->right, k1, k2);
		printbwK1AndK2(root->left, k1, k2);
	}

	if(root->data > k2) {
		printbwK1AndK2(root->left, k1, k2);
	}

	if(root->data < k1) {
		printbwK1AndK2(root->right, k1, k2);
	}

}

int main() {
	Node* root = takeInput();
	int k1, k2;
	cin >> k1>> k2;
	// cout<<root->data<<endl;
	printbwK1AndK2(root, k1, k2);
}