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

void printStack(stack<Node*> s) {
    if(s.empty()) {
        cout<<endl;
        return;
    }
    //cout<<"stac"<<endl;
    cout<<(s.top()->data)<<' ';
    s.pop();
    printStack(s);
}

void printAllPaths(Node* root, stack<Node*>& s) {
    if(!root)   return;

    s.push(root);

    if(root->left==NULL && root->right == NULL) {
            //cout<<root->data<<endl;

        printStack(s);
        s.pop();
        return;
    }

    printAllPaths(root->left, s);
    printAllPaths(root->right, s);
    s.pop();    //jab dono leftb adn right chilren cater ho gaye, then move up. Matalb parent ko hata do.
}