#include<iostream>

using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int t1[n1],t2[n2];
    
    int i=0,j=0;
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

void mergeSort(int arr[],int left,int right){

    if (left<right){   
        int mid = left + (right-left)/2;

        //Sort 2 halves
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
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
    mergeSort(arr,0,n-1);
    //display
    show(arr,n);
    return 0;
}

