#include "tree.h"

class LL {
public:
    Node* c1;
    LL* next;
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
