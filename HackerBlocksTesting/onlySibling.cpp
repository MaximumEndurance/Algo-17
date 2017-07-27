#include<iostream>

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

void InOrder(Node* root) {
	if(!root) return;
		cout<<root->data<<' ';

	InOrder(root->left);
	InOrder(root->right);
}

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

void printOnlySibling(Node* root) {
    if(!root) return;

    if(root->left) {
        if(root->right == NULL) {
            cout<<(root->left->data)<<endl;
        }
        printOnlySibling(root->left);
    }

    if(root->right) {
        if(root->left == NULL) {
                  cout<<(root->right->data)<<endl;
        }
        printOnlySibling(root->right);
    }
}

int main() {
    Node* root = NULL;
    input(root);
    printOnlySibling(root);

	return 0;
}