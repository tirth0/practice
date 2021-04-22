#include<iostream>
#include<vector>
using namespace std;


    vector<int> merge(vector<int> a,vector<int> b){
        int m = a.size(), n = b.size();
        vector<int> res(m+n,0);
        int i=0,j=0,k=0;
        while (i<m && j<n){
            if (a[i]<b[j]){
                res[k++] = a[i++];
            }
            else {
                res[k++] = b[j++];
            }
        }
        while (i<m){
            res[k++] = a[i++];
        }
        while (j<n){
            res[k++] = b[j++];
        }
        return res;
    }

    void findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        vector<int> res = merge(nums1,nums2);
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(5);
        int n = res.size()/2;float median = 0.0;
        for (auto i : res){
            cout << i << " ";
        }
        cout << endl;
        if (res.size()%2 == 0){
            median = ((float)res[n] + (float)res[n-1])/2.0;
        }
        else median = ((float)res[n]);
        cout << median;
        
    }

    int main(){
        vector<int> a = {};
        vector<int> b = {2,3};
        findMedianSortedArrays(a,b);
        return 0;
    }