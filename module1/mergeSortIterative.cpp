#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int t1[n1],t2[n2];
    
    int i,j;
    for (i=0;i<n1;i++){
        t1[i] = arr[l+i];
    }
    for (j=0;j<n2;j++){
        t2[j] = arr[m+1+j];
    }

    i=j=0;
    int k = l;
    while (i<n1 && j<n2){
        if (t1[i]<=t2[j]){
            arr[k] = t1[i];
            i++;
        }
        else{
            arr[k] = t2[j];
            j++;
        }
        k++;
    }

    //copy remaining elements
    while (i<n1){
        arr[k] = t1[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k] = t2[j];
        i++;
        j++;
    }


}

//GFG
void mergeSort(int arr[], int n)
{
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting 
           // point of right
           int mid = min(left_start + curr_size - 1, n-1);
 
           int right_end = min(left_start + 2*curr_size - 1, n-1);
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
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
    mergeSort(arr,n);
    //display
    show(arr,n);
    return 0;
}


