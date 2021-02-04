#include<iostream>

using namespace std;


struct BST{
    int data;
    BST * left;
    BST * right;
    BST(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BST * insert(BST * root,int data){
    if (root == NULL) {
        root = new BST(data);
    }
    else if (root->data > data) root -> left = insert(root->left,data);
    else root-> right = insert(root->right,data);
    return root;
}

void preOrder(BST * root){
    if (root == NULL) return;

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BST * root){
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
} 

BST * arrayToBST(int arr[],int lef,int righ){
    if (lef>righ) return NULL;
    int mid = (lef + righ)/2;
    BST * ptr = new BST(arr[mid]);
    ptr->left = arrayToBST(arr,lef,mid-1);
    ptr->right = arrayToBST(arr,mid+1,righ);
    return ptr;
}

BST * findMinNode(BST * root){
    if (root==NULL  || root->left== NULL) return root;
    BST * ptr = findMinNode(root -> left);
    if (ptr->left == NULL) return ptr;
    ptr = findMinNode(root -> right);

    return ptr;
}

BST * deleteNode(BST * root,int search){
    if (root == NULL) return root;
    else if(search<root->data) root->left = deleteNode(root->left,search);
    else if(search>root->data) root->right = deleteNode(root->right,search);
    else{
        if (root->left ==NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            BST * temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            BST * temp = root;
            root = root->left;
            delete temp;
        }
        else{
            BST * temp = findMinNode(root->right);;
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

    return root;
}


int main(){
    BST * root; root = NULL;
    int arr[] = {1,2,3,4,5,6,7};
    root = arrayToBST(arr,0,6);
    preOrder(root);
    root = deleteNode(root,5);
    cout << "\n";
    inOrder(root);
    
}