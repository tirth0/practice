#include<iostream>
#define SIZE 10
using namespace std;

struct element{
    int item;
    int priority;
    element(int n,int p = 0){
        item = n;
        priority = p;
    }
};

struct queue{
    int rear;
    int front;
    element * elem[SIZE];
    queue(int rear,int front){
        this->rear = rear;
        this->front = front;
    }
};

bool isEmpty(queue * pq){
    if (pq->front == -1 && pq->rear == -1)
        return true;
    return false;
}

bool isFull(queue * pq){
    
}

void enQueue(int n,int priority){

}

