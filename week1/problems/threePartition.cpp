//3 Way Quick Sort based on the dutch national flag problem
//3 parts division:
//Less than pivot
//equal to pivot
//greater than pivot

//3 way partitioning
//sort an array of any 3 numbers etc.
//selecting first element as pivot
#include<iostream>
using namespace std;


void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int a[], int low, int high, int& i, int& j)
{
    // To handle 2 elements
    if (high - low <= 1) {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }

    /*
    1 1 2 6 5 4 4 6 7
      - +*

    +=low;
    -=mid
    *=high
    pivot = 2
    */
 
    int mid = high;
    int pivot = a[low];
    while (mid >= low) {
        if (a[mid] > pivot)
            swap(&a[high--], &a[mid--]);
        else if (a[mid] == pivot)
            mid--;
        else if (a[mid] < pivot)
            swap(&a[mid], &a[low++]);
    }
 
    // update i and j
    
    i = mid;
    j = high+1; 
    // or low+1 
}

void quickSort(int a[],int low,int high){
    if (low >= high) // 1 or 0 elements
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, low, high, i, j);
 
    // Recur two halves
    quickSort(a, low, i);
    quickSort(a, j, high);
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
