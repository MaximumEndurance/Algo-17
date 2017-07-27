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

Node* takeInput() {
    int data;
    cin >> data;
    
    if(data == -1)  return NULL;
    
    Node* root = new Node(data);
    std::queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        
        int leftData;
        cin >> leftData;
        
        if(leftData!=-1) {
            Node* newNode = new Node(leftData);
            currNode->left = newNode;
            q.push(newNode);
        }
        
         int rightData;
        cin >> rightData;
        
        if(rightData!=-1) {
            Node* newNode = new Node(rightData);
            currNode->right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

void printNormal(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<endl;

    printNormal(root->left);
    printNormal(root->right); 
}

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

int main() {
    Node* root = takeInput();
    printNormal(root);
    print(root);
}
