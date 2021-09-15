#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;


//search in rotated sorted array
// int search(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int high = nums.size()-1,low=0,mid;
//         bool flag = false;
//         while (low<=high){
//             mid = low+(high-low)/2;
//             if (target > nums[mid]) low = mid+1;
//             else if (target < nums[mid]) high = mid - 1;
//             else{
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag) return mid;
//         else return -1;
// }

int main(){
    vector<int> vi = {4,5,6,7,0,1,2};
    int target = 4,res = -1;
    map<int,int> mp;
    for (int i=0;i<vi.size();i++){
        mp.insert(make_pair(vi[i],i));
    }
    sort(vi.begin(),vi.end());
    if (binary_search(vi.begin(),vi.end(),target)){
        res = mp.at(target);
    }
    cout << res;
    return 0;
}