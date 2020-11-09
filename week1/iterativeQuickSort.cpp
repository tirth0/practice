#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int i = low-1;
    int pivot = arr[high];
    for (int j=low;j<high;j++){
        if (arr[j]<=pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
        swap(&arr[j],&arr[i]);
    }
    swap(&arr[j],&arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high){
    int stack[high-low+1];
    int top=-1;
    stack[++top] = low;
    stack[++top] = high;
    while (top>=0){
        int h = stack[top--];
        int l = stack[top--];

        int pi = partition(arr,l,h);

        if (pi-1>l){
            stack[++top] = l;
            stack[++top] = pi-1;
        }
        if (pi+1<h){
            stack[++top] = pi+1;
            stack[++top] = h;
        }

    }
}

void show(int arr[],int x){
    cout << "sorted array" << endl;
    for (int i=0;i<x;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    cout << "Enter Array Length\n";
    int x;
    cin >> x;
    int arr[x];
    cout << "Enter array values\n";
    for (int i=0;i<x;i++)
        cin>>arr[i];

    quickSort(arr,0,x-1);

    show(arr,x);

}
