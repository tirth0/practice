#include<iostream>
#include<vector>
using namespace std;

int peakFinder(vector<int> &a){
    int l=0,r=a.size()-1,mid;
    while(l<=r){
        mid = l+(r-l)/2;
        if (a[mid]<a[mid+1])
            l=mid+1;
        else if (a[mid]<a[mid-1])
            r=mid-1;
        else
            return a[mid];
    }
}