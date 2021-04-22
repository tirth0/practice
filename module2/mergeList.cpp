#include<iostream>
#include<algorithm>
#include<vector>


//program to merge two sorted linked lists

using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node * insertElem(int data,Node * head){
    Node * ptr = new Node(data);
    // cout << "element inserted is " << data << endl;
    if (head==NULL){
        head = ptr;
    }
    else{
        Node * root = head;
        while (root->next!=NULL){
            root = root->next;
        }
        root->next = ptr;
    }
    return head;
}

void display(Node*head){
    if (head == NULL) cout << "List empty";
    else{
        while (head!=NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

Node * merge(Node * list1,Node * list2,int c1,int c2){
    Node * ptr1 = list1, * ptr2 = list2;
    Node * head = NULL;int i=0,j=0;
    int mn = min(c1,c2);
    while (ptr1!=NULL && ptr2!=NULL){
        if (ptr1->data>ptr2->data){
            head = insertElem(ptr2->data,head);
            // cout << "element inserted is " << ptr2->data << endl;
            ptr2 = ptr2->next;
    
        }
        else{
            head = insertElem(ptr1->data,head);
            // cout << "element inserted is " << ptr1->data << endl;
            ptr1 = ptr1->next;
            
        }
    }
    
    while (ptr1!=NULL){
        head = insertElem(ptr1->data,head);
        ptr1=ptr1->next;
        
    }
    while (ptr2!=NULL){
        head = insertElem(ptr2->data,head);
        ptr2=ptr2->next;
        
    }
    return head;
}


int main(){
    Node * list1 = NULL, * list2 = NULL;
    int c1=0,c2=0;
    cout << "First list" << endl;
    while (true){
        cout<< "Enter element, -1 for exit" << endl;
        int x; cin >> x;
        if (x==-1) break;
        list1 = insertElem(x,list1);
        c1++;
    }
    cout << "second list" << endl;
    while (true){
        cout<< "Enter element, -1 for exit" << endl;
        int x; cin >> x;
        if (x==-1) break;
        list2 =insertElem(x,list2);
        c2++;
    }
    display(list1);
    display(list2);

    Node * mergeList = merge(list1,list2,c1,c2);
    display(mergeList);

    return 0;
}
