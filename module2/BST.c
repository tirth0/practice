#include<stdio.h>
#include<math.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

Node * constructor(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node * findPosition(int data,Node * root){   
    if (data > root->data && root->right!=NULL){
        findPosition(data,root->right);
    }
    else if(data < root->data && root->left!=NULL){
        findPosition(data,root->left);
    }
    else{
        return root;
    }
}

Node * insert(int data,Node * root){
    Node * newNode = constructor(data);
    if (root == NULL){
        root = newNode;
    }
    else {
        Node * sptr = findPosition(data,root);
        if (data>sptr->data)
            sptr->right = newNode;
        else
            sptr->left = newNode;
    }
    return root;
}

void inOrder(Node * root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}



int main(){
    
    Node * root = NULL;
    while (1){
        printf("\n1.Insert\n2.Display\n");
        int ch;
        scanf("%d",&ch);
        if (ch == 1 ){
            printf("\nEnter data : ");
            int d;
            scanf("%d",&d);
            root = insert(d,root);
        }
        else if (ch == 2){
            inOrder(root);
        }
        else break;
    }
    return 0;
}