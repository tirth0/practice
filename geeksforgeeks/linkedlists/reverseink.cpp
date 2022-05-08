#include<iostream>
#include<stdlib.h>


struct Node{
    int data;
    Node * next;
    Node(int data){
        this->data = data;
    }    
};


class LinkedList{
    public:
    int n;
    LinkedList(int n){
        this->n = n;
    }

    Node * createNode(int data, Node * next){
        Node * newNode = new Node(data);
        newNode->next = next;
    }

    Node * insert

};