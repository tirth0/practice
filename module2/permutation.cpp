
#include<vector>
#include<algorithm>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

// program to find whethere a permutation function is odd or even
//Hackerrank Larry's Arrays https://www.hackerrank.com/challenges/larrys-array/problem

int findPermutations(vector<int> v, int l){
    vector<int> id = v;
    sort(id.begin(),id.end());
    vector<int> visited;
    map<int,int> mp;
    int itr = 0,itr2 = 0;
    int sgn = 0;
    while (l>0){
        mp.insert(make_pair(id[itr],v[itr]));
        itr++;
        l--;
    }
    for (auto it = mp.begin();it!=mp.end();it++){
        int start = it->first,end = it->second,ctr=0;
        if (find(visited.begin(),visited.end(),start)!=visited.end()) continue;
        visited.push_back(start);
        while(end != start){
            int st = end;
            end = mp.at(st);
            visited.push_back(st);
            ctr++;
        }
        sgn+=ctr;
        cout << ctr << endl;
    }
    return sgn;
}

int main(){
    vector<int> v ={1,2,3,5,4};
    int l = v.size();
    int sgn = findPermutations(v,l);
    if (sgn%2!=0) cout << "odd";
    else cout << "even";
    return 0;
}
