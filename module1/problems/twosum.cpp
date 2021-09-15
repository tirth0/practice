//leetcode
#include<bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& inp, int target) {
        int i=0, j = inp.size()-1;
        multimap<int,int> mp;
        for (int k=0;k<inp.size();k++){
            mp.insert(make_pair(inp[k],k));
        }
        sort(inp.begin(),inp.end());
        
        while ((i!=j && (inp[i] + inp[j] != target) )){
            if (inp[i] + inp[j] < target) i++;
            else j--;
        }
        if (inp[i]==inp[j]){
            auto it = mp.equal_range(inp[i]);
            auto iter = it.first;
            int p1 = iter->second;
            iter++;
            int p2 = iter->second;
            vector<int> res = {p1,p2};
            return res;
        }
        else
            {   
                auto it = mp.find(inp[i]);
                auto jt = mp.find(inp[j]);
                vector <int> res = {it->second,jt->second};
                return res;
            }
    }
};