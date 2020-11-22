#include<iostream>
#include<cstring>
#include<climits>
#define SIZE 10
using namespace std;



struct Dequeue{
    int front;
    int rear;
    int queue[SIZE];
    Dequeue(){
        front = -1;
        rear = -1;
    }
};

bool isFull(Dequeue * dq){
    if ((dq->front==0 && dq->rear == SIZE-1) || (dq->front == dq->rear + 1))
        return true;
    return false;
}

bool isEmpty(Dequeue * dq){
    if (dq->front == -1 && dq->rear == -1)
        return true;
    return false;
}


void insertFront(Dequeue * dq,int inp){
    if (isFull(dq))
        cout << "Queue Overflow";
    else if (isEmpty(dq)){
        dq->front = dq->rear = 0;
        dq->queue[dq->front] = inp;
    }
    else{
        int f = dq->front;
        f = (--f+SIZE)%SIZE;
        dq->front = f;
        dq->queue[dq->front] = inp;
    }
}

void insertRear(Dequeue * dq,int inp){
    if (isFull(dq))
        cout << "Queue Overflow";
    else if (isEmpty(dq)){
        dq->front = dq->rear = 0;
        dq->queue[dq->rear] = inp;
    }
    else{
        int r = dq->rear;
        r = ++r % SIZE;
        dq->rear = r;
        dq->queue[dq->rear] = inp;
    }
}

void deleteFront(Dequeue * dq){
    if (isEmpty(dq))
        cout << "Queue Empty";
    else if (dq->front == dq->rear)
        dq->front = dq->rear = -1; 
    else{
        int f = dq->front;
        
        f = ++f%SIZE;
        dq->front = f;
    } 
}

void deleteRear(Dequeue * dq){
    if (isEmpty(dq))
        cout << "Queue Empty";
    else if (dq->front == dq->rear)
        dq->front = dq->rear = -1; 
    else{
        int r = dq->rear;
        r = --r%SIZE;
        dq->rear = r;
    } 
}



void display(Dequeue * dq){
    if (isEmpty(dq)){
        cout << "Queue Empty";
    }
    else{
        int f = dq->front;
        int r = dq->rear;
        while(f!=r){
            cout << dq->queue[f] << " ";
            f = (++f)%SIZE;
        }
        cout << dq->queue[r];
    }
}


int main(){
    Dequeue * dq = new Dequeue();
    insertFront(dq,6);
    insertFront(dq,7);
    insertFront(dq,8);
    insertFront(dq,9);
    insertFront(dq,10);
    insertRear(dq,9);
    insertRear(dq,11);
    insertRear(dq,12);
    insertRear(dq,13);
    insertRear(dq,14);
    display(dq);
    cout << "\n";
    deleteFront(dq);
    deleteFront(dq);
    deleteFront(dq);
    deleteFront(dq);
    deleteRear(dq);
    deleteRear(dq);
    display(dq);
    return 0;
}