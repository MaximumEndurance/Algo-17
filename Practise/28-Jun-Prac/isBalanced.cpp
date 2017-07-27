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

bool flag = 0;

void check(Node* root, int countLeft, int countRight) {
    if(root == NULL)     return;
    cout<<root->data<<endl;

    
    if(root->left) {
        cout<<"left "<<countLeft<<endl;
        ++countLeft;
        check(root->left, countLeft, countRight);
    }
    
    if(root->right) {
        ++countRight;
        check(root->right, countLeft, countRight);
    }        
    if((countRight - countLeft > 1) || (countLeft - countRight) > 1) {
    flag =1;
    return;
    }
   cout<<countLeft<<' '<<countRight<<endl;
}

// void checkBalanced(Node* root) {
//     if(root == NULL) return;
    
//     int countLeft = getNodes(root->left);
//     int countRight = getNodes(root->right);
    
//     if(countRight - countLeft <= 1 || (countLeft - countRight) <= 1)
//     cout<<"true"<<endl;
//     else
//     cout<<"false"<<endl;
// }

int main() {
    Node* root = NULL;
    input(root);
    //InOrder(root);
    //checkBalanced(root);
    check(root, 0, 0);
    if(flag == 0){
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

}