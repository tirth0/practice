#include<iostream>

//Quick Sort Algorithm
//Select a pivot element and arrange elements
//on either side of array(greater or lesser than pivot)
//recursively repeat for left and right subarrays

//First element is pivot

using namespace std;


void swap(int *a,int *b){
    int  temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = high+1;
    for (int j=high;j>low;j--)
        if (arr[j]>pivot){
            i--;
            swap(&arr[j],&arr[i]);
        }
    swap(&arr[--i],&arr[low]);
    return i;
}



void quickSort(int arr[],int low,int high){
    if (low>=high)
        return;
    int partition_point = partition(arr,low,high);

    //left subarray
    quickSort(arr,low,partition_point-1);
    //right subarray
    quickSort(arr,partition_point+1,high);
}

void show(int arr[],int n){
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    cout << "enter size\n";
    int n; cin >> n;
    int arr[n];
    cout << "enter elements";
    for (int i=0;i<n;i++) cin >> arr[i];
    //method call
    quickSort(arr,0,n-1);
    //display
    show(arr,n);
    return 0;
}

