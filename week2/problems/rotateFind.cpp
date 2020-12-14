//Leet code problem find the smallest number in a rotated sorted array
#include<iostream>
#include<vector>
using namespace std;

//rotated sorted Array binary search
int findMin(vector<int>& a) {
        int high=a.size()-1,low=0,mid=low+(high-low)/2;
        if (a.size()==1) return a[0];
        if (a[high]>a[low]) return a[low];
        while(low<=high){
            mid=low+(high-low)/2;

            if (a[mid]>a[mid+1]) return a[mid+1];
            else if (a[mid-1]>a[mid]) return a[mid];
            else if (a[mid]>a[0]) low = mid+1;
            else high = mid-1;
        }
        return -1;
}


int main(){
    vector<int> arr = {3,4,5,1,2};
    int small = findMin(arr);
    cout << small;
    return 0;
}