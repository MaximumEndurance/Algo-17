#include "tree.h"
#include <stdlib.h>

void inputTandF(Node* &root) {
    
    int data;
     cin >> data;
     root = new Node(data);
     //cout<<root->data<<endl;
     
     bool hasALeftChild, hasARightChild;
     string leftInput, rightInput;
     
     cin >> leftInput;
     
     hasALeftChild = (leftInput == "true") ? 1 : 0;
     
     if(hasALeftChild) {
         inputTandF(root->left);
     }
     
     cin >> rightInput;
     hasARightChild = (rightInput == "true") ? 1 : 0;

     
     if(hasARightChild) {
         inputTandF(root->right);
     }

     return;
}


bool isleafNode(Node* root) {
    if(!root)   return 1;

    return (root->left==NULL && root->right==NULL);
}

void deleteAllLeaf(Node* root) {
    if(!root) return;

    if(isleafNode(root->left)) {
        root->left = NULL;
    }
    if(isleafNode(root->right)) {
        root->right = NULL;
    }

    deleteAllLeaf(root->left);
    deleteAllLeaf(root->right);
}

void printWithEnd(Node* root) {
    if(!root)   return;
    // cout<<(root->left ? buffer : "END");
    if(root->left) {
        cout<<root->left->data;
    }
    else {
        cout<<"END";
    }

    cout<<" => "<<root->data<<" <= ";

    if(root->right) {
        cout<<root->right->data;
    }
    else {
        cout<<"END";
    }
    cout<<endl;
    printWithEnd(root->left);
    printWithEnd(root->right);
    //cout<<(root->right ? root->right->data : "END")<<endl;

 }

int main() {
    Node* root = NULL;
    inputTandF(root);
    deleteAllLeaf(root);
    printWithEnd(root);
}