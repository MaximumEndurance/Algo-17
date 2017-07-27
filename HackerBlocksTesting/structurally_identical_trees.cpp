#include <iostream>
#include <vector>

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

// std::vector<int> vec1;
bool isInOrder = 1;
void InOrder1(Node* root1, Node* root2) {
    if(!root1 && !root2) { return;} 
    if((root1 && !root2) || (!root1 && root2)) {

     isInOrder = 0;
     return;
 }
    // cout<<root1->data<<' '<<root2->data<<endl; 

    if(root1->data != root2->data) {
        isInOrder = 0;
        return;
    }

    InOrder1(root1->left, root2->left);
    InOrder1(root1->right, root2->right);
}

// std::vector<int> vec2;

// void InOrder2(Node* root) {
//     if(!root) return;
//     vec2.push_back(root->data);
//     InOrder2(root->left);
//     InOrder2(root->right);
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

}



int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    input(root1);
    input(root2);
    // InOrder1(root1);
    // InOrder2(root2);
    //cout<<(InOrder(root1, root2)?"true":"false")<<endl;
    //printOnlySibling(root);

//     if(vec1.size() == vec2.size()) {
//         std::vector<int>::iterator jj =vec2.begin();
//         std::vector<int>::iterator ii = vec1.begin();
//     for(; ii!=vec1.end();++ii, ++jj) {
//         if(*ii != *jj)
//             break;
//     }
//     cout<<(ii == vec1.end() ? "true" :"false")<<endl;
// }  

// else{
//     cout<<"false"<<endl;
// }
    InOrder1(root1, root2); 
    cout<<(isInOrder ?"true": "false")<<endl;


    return 0;

}