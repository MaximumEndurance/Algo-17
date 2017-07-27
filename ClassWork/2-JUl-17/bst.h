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
    if(!root)   {
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
    Node* root;
    while(cin >> num && num!=-1) {

    root= insertInBST(root, num);
    }
    return root;
}

Node* search(Node* root, int num) {
    if(!root)   {
        return NULL;
    }

    if(root->data == num) {
        return root;
    }
    else if(num > root->data){
        return search(root->right, num);
    }
    else {
        return search(root->left, num);
    }
}