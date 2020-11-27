//leet code find first and last index
#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int> nums, int target) {
        int low = 0, high = nums.size(),mid;
        bool flag = false;
        if (low != high){
            while(low<=high){
                mid = low + (high-low)/2;
                if (nums[mid]<target) low = mid+1;
                else if (nums[mid]>target) high = mid-1;
                else{
                    flag = true;
                    break;
                }
            }
        }
        vector<int>res;
        if (flag){
            int i=mid,j=mid;
            while ((i+1)<nums.size() && nums[i+1] == target) i++;
            while((j-1)>=0 && nums[j-1] == target) j--;
            res = {j,i};
        }
        else{
            res = {-1,-1};
        }
        return res;
    }


int main(){
    vector<int> vi = {2,2};
    int target = 3;
    vector<int> res = searchRange(vi,target);
    for (auto i:res) cout << i << " ";
}