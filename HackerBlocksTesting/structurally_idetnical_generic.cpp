#include <iostream>
#include <vector>

using namespace std;


class Node {
    public:
    int data;
    std::vector<Node*> vec;
    
    Node(int val) {
        data = val;
    }
};
bool isInOrder = 1;
void InOrder(Node* root1, Node* root2) {
    if((root1 == NULL) && (root2== NULL)) return;
    //     if(!root1 && !root2) { return;} 
    // if((root1 && !root2) || (!root1 && root2)) {
        if((root1 == NULL) ^ (root2 == NULL)) {
     isInOrder = 0;
     return;
        }
    // cout<<root1->data<<' '<<root2->data<<endl; 
        cout<<(root1 == NULL)<<' '<<(root2== NULL)<<endl;
    if(root1->data != root2->data) {
        isInOrder = 0;
        return;
    }

    if(root1->vec.size() != root2->vec.size()) {
        isInOrder = 0;
        return;
    }
    cout<<root1->data<<' '<<root2->data<<endl;
    vector<Node*>::iterator ii, jj;
    for(ii = root1->vec.begin(), jj = root2->vec.begin(); ii!= root1->vec.end(); ++ii, ++jj) {
        
            root1->vec.push_back((*ii));
            root2->vec.push_back((*jj));

        InOrder(*ii, *jj);
    }
    
}

// std::vector<int> vec1;
// void InOrder1(Node* root1, Node* root2) {
//     if(!root1 && !root2) { return;} 
//     if((root1 && !root2) || (!root1 && root2)) {

//      isInOrder = 0;
//      return;
//  }
//     // cout<<root1->data<<' '<<root2->data<<endl; 

//     if(root1->data != root2->data) {
//         isInOrder = 0;
//         return;
//     }

//     InOrder1(root1->left, root2->left);
//     InOrder1(root1->right, root2->right);
// }

// std::vector<int> vec2;

// void InOrder2(Node* root) {
//     if(!root) return;
//     vec2.push_back(root->data);
//     InOrder2(root->left);
//     InOrder2(root->right);
// }

Node* InputIt() {
    int data;
    cin >> data;

    Node* root = new Node(data);

    int children;
    cin >> children;

    if(children == 0){
        return root;
    }
    //cout<<root->data<<endl;
    while(children--) {
        //cout<<'1'<<endl;
        Node* newNode = InputIt();
        root->vec.push_back(newNode);
    }
    return root;
}



int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = InputIt();
    root2= InputIt();

    InOrder(root1, root2); 
    cout<<"h"<<endl;
    cout<<(isInOrder ?"true": "false")<<endl;


    return 0;

}