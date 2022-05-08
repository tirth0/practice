#include<iostream>

using namespace std;


bool solve(int * arr, int n){

    for (int i=0;i< n;i++){
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main(){
    int arr[] = {1, 2, 3, 4, 6, 8};
    bool isSorted = solve(arr, sizeof(arr)/sizeof(arr[0]));
    cout << isSorted << endl;
}