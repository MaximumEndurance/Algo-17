#include<iostream>
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

// void InOrder(Node* root) {
// 	if(!root) return;
// 		cout<<root->data<<' ';

// 	InOrder(root->left);
// 	InOrder(root->right);
// }

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

void print(Node* root) {

    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.empty() == false) {
        
    
    Node* currNode = q.front();
    q.pop();


    if(currNode == NULL) {   //NULL is being used as a delimiter
        cout<<endl;
            
        if(!q.empty()) {
            q.push(NULL);
        }
        continue;
    }
        cout<<currNode->data<<' ';

         if(currNode->left) {
             q.push(currNode->left);
         }
         
         if(currNode->right) {
             q.push(currNode->right);
         }
         
    }
}

int main() {
    Node* root = NULL;
    input(root);
    print(root);
}