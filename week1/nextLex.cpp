#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//find next permutation



vector<int> findNonIncreasingSubSeq(vector<int> v){
    int i=0,j=0,pos1,pos2;
    int maxim = INT_MIN,len=0;
    while (j<v.size()-1){
        if (v[j]>=v[j+1]){
            len++;
        }
        else {
            if (len>maxim){
                pos1 = i+1;pos2 = j;
                maxim = len;
            }
            i = j;
            len=0;
        }
        j++;

    }
    if (len>maxim){
        pos1 = i==0?0 : i+1;pos2 = j;
        maxim = len;
    }
    vector<int> result = {pos1,pos2,maxim};
    return result;
}


int main(){
    vector<int> v;
    int n;cin >> n;
    while (n>0){
        int x; cin >> x;
        v.push_back(x);
        n--;
    }
    vector <int> result = findNonIncreasingSubSeq(v);
    
    if (result[2] == 0){
        cout << "no available subsequences";
    }
    else{
        for (int i=result[0];i<=result[1];i++){
            cout << v[i] << " ";
        }
    }
    return 0;
}
