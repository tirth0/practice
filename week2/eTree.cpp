#include<iostream>

struct Node{
    char data;
    Node * left;
    Node * right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

struct stack{
    Node *eTree[50];
    int top;
    stack(){
        this->top = -1;
    }
};

stack * st = new stack();

char pf[50];

bool isOperator(char t){
    return t=='+' || t=='-' || t=='*' || t=='/' || t=='^';
}

void push(Node * node){
    st->eTree[st->top++] = node;
}

Node * pop(){
    return st->eTree[st->top--];
}

int calculate(Node * top){
    char d = top->data;
    if (!isOperator(d))
        return d-48;
    else{
        if (d=='+') return calculate(top->left)+calculate(top->right);
        if (d=='-') return calculate(top->left)-calculate(top->right);
        if (d=='/') return calculate(top->left)/calculate(top->right);
        if (d=='*') return calculate(top->left)*calculate(top->right);
    }
}


void constructTree(char* suffix){
    char s;
    s = suffix[0];
    for (int i=0;s != '\0';s++){
        if (!isOperator(s)){
            Node * newNode = new Node(s);
            push(newNode);
        }
        else{
            
            Node * newNode = new Node(s);
            newNode -> right = pop();
            newNode ->left = pop();
            push(newNode);
        }
        s = suffix[i];
    }
}

