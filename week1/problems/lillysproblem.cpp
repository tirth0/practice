#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

//Lilly's Problem Hackerrank

void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//2 5 3 1
/*
 1 2 3 5
 1 3 
 2 0
 3 2
 5 1
 
 pass1: 1 5 3 2
 
*/

void solve(vector<int> arr){
    vector<int> copy = arr;
    vector<int> cp2 = arr;
    
    sort(copy.begin(),copy.end());
    ll sw=0;
    map <int,int> ind;
    for (int i=0;i<copy.size();i++){
        ind.insert(make_pair(arr[i],i));
    }
    map <int,int> ind2 = ind;
    // for (auto it = ind.begin();it!=ind.end();it++){
    //     cout << it->first << "\t" << it->second << endl;
    // }
    for (int i=0;i<arr.size();i++)
        if (copy[i]!=arr[i]){
            auto it1 = ind.find(arr[i]);
            auto it2 = ind.find(arr[ind.at(copy[i])]);
            swap(&arr[i],&arr[ind.at(copy[i])]);
            
            it1->second = it2->second;
            sw++;
        }
    // for (auto it = ind2.begin();it!=ind2.end();it++){
    //     cout << it->first << "\t" << it->second << endl;
    // }
    /*
    3 4 2 5 1 
    1 4
    2 2
    3 0
    4 1
    5 3
    
    first pass : 3 4 2 5 1
    second pass : 3 4 5 2 1
    */
    ll sw2=0;sort(copy.begin(),copy.end(),greater<int>());
    for (int i=arr.size()-1;i>=0;i--){
        if (copy[i]!=cp2[i]){
            auto it1 = ind2.find(cp2[i]);
            auto it2 = ind2.find(cp2[ind2.at(copy[i])]);
            swap(&cp2[i],&cp2[ind2.at(copy[i])]);
            
             
            it1->second = it2->second; 
            sw2++;
        }
    }
    // for (auto it = ind2.begin();it!=ind2.end();it++){
    //     cout << it->first << "\t" << it->second << endl;
    // }
    
    
    cout << min(sw,sw2);
}

int main(){
    IOS;
    int n;
    vector<int> v;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >>x;
        v.push_back(x);
    }
    solve(v);
}