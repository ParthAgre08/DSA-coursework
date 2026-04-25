#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:

    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        left = right= NULL;
    }

};

static int idx=-1;
Node* BuildTree(vector <int> &preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);

    return root;
}

// preorder traversal means visit root first then root->left then root->right
void preorderTraversal(Node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal means visit root->left first then root the root->right
void inorderTraversal(Node *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}



int main(){
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root =  BuildTree(preorder);

inorderTraversal(root);

return 0;
}