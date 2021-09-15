#include<iostream>
#include<queue>

using namespace std;

struct myBinTree{
    int marks;
    myBinTree * left;
    myBinTree * right;
};

queue<myBinTree *> Q;

myBinTree * createBinTree(){
    myBinTree * ptr = new myBinTree();
    int m;
    cout << "Enter data(-1 for no data) \n";
    cin >> m;
    ptr->marks = m;
    if (m==-1)
        return NULL;
    //Left
    cout << "Enter the left child of" << m << ":\n";
    ptr->left = createBinTree();
    //right 
    cout << "Enter the right child of" << m << ":\n";
    ptr->right = createBinTree();
    return ptr;
}


void preOrder(myBinTree * root){
    if (root == NULL) return;

    cout << root->marks;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(myBinTree * root){
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->marks;
    inOrder(root->right);
}

void postOrder(myBinTree * root){
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->marks;
}

void levelOrder(){
    if (Q.empty()) return;
    myBinTree * current = Q.front();
    cout << current->marks << " ";
    if (current->left!=NULL) Q.push(current->left);
    if (current->right!=NULL) Q.push(current->right);
    Q.pop();
    levelOrder();

}

myBinTree * preSearch(myBinTree * current,int search){
    if (current == NULL) return NULL;
    if (current->marks == search){
        return current;
    }
    myBinTree * ptr = preSearch(current->left,search);
    if (ptr!=NULL && ptr->marks == search){
        return ptr;
    }
    ptr = preSearch(current->right,search);
    return ptr;
}

myBinTree * inSearch(myBinTree * current,int search){
    if (current == NULL) return NULL;
    myBinTree * ptr = inSearch(current->left,search);
    if (ptr!=NULL && ptr->marks == search){
        return ptr;
    }
    ptr = inSearch(current->right,search);
    return ptr;
}

myBinTree * BFS(int search){
    if (Q.empty()) return NULL;
    myBinTree * current = Q.front();
    if (current->marks == search){
        return current;
    }
    myBinTree * ptr;
    if (current->left!=NULL){
        Q.push(current->left);
    }
    if (current->right!=NULL){
        Q.push(current->right);
    }
    Q.pop();
    ptr = BFS(search);
    return ptr;
}


int main(){
    myBinTree * root = createBinTree();
    Q.push(root);
    while(true){
        cout << "\nEnter \n1.Inorder\n2.PostOrder\n3.PreOrder\n4.Level Order\n5.PreSearch\n6.InSearch\n7.BFS\n";
        int ch;
        cin >> ch;
        if (ch == 1) inOrder(root);
        else if (ch==2) postOrder(root);
        else if (ch==3) preOrder(root);
        else if (ch == 4) {
            levelOrder();
        }
        else if(ch==5){
            cout << "enter search element\n";
            int x;cin>>x;
            myBinTree * ptr = preSearch(root,x);
            if (ptr == NULL) cout << "NULL";
            else
                cout<<"Node found.\nData in node :"<< ptr->marks;
        }
        else if(ch==6){
            cout << "enter search element\n";
            int x;cin>>x;
            myBinTree * ptr = inSearch(root,x);
            if (ptr == NULL) cout << "NULL";
            else
                cout<<"Node found.\nData in node :"<< ptr->marks;
        }
        else if(ch==7){
            cout << "enter search element\n";
            int x;cin>>x;
            myBinTree * ptr = BFS(x);
            if (ptr == NULL) cout << "NULL";
            else
                cout<<"Node found.\nData in node :"<< ptr->marks;
            queue<myBinTree *> empty;
            Q = empty; Q.push(root);
        }
        else break;
    }
    
    return 0;
}