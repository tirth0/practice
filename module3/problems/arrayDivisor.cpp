#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<set>
#include<deque>
#include <cstring>
#define mod 1000000007
typedef long long int ll;
using namespace std;
using namespace std::chrono;

vector<int> spf(1000001);
void sieve(){
    
    spf[1] = 1;
    for (int i=2;i<1000000;i++)
        spf[i] = i;
    
    for (int i=4;i<1000000;i+=2)
        spf[i] = 2;
    
    for (int i=3;i*i<1000000;i++){

        if (spf[i] == i){

            for (int j=i*i;j<1000000;j+=i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int getFactors(int x){
    int ct=0;set<int> s;
    while(x!=1){
        s.insert(spf[x]);
        x = x/spf[x];
    }
    return s.size();
}

vector<int> countPrime(vector<int> A){
    
    for (int i=0;i<A.size();i++){
        A[i] = getFactors(A[i]);
    }
    return A;
}

void solve(vector<int>&A,vector<int> &OG,int B){
    deque<int> Q(B);
    int gsum=0;
    int i;
    for (i=0;i<B;i++){
        while(!Q.empty() && A[i]>A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    for (;i<A.size();i++){
        gsum = gsum%mod + OG[Q.front()]%mod;

        while (!Q.empty() && Q.front()<=i-B)
            Q.pop_front();
        
        while (!Q.empty() && A[i]>A[Q.back()])
            Q.pop_back();
        
        Q.push_back(i);
    }

    gsum = gsum%mod + OG[Q.front()]%mod;
    cout << gsum << endl;
}

int main(){
    
    vector<int> A = {18,36,15,210};
    sieve();
    vector<int> primeCt = countPrime(A);
    auto start = high_resolution_clock::now(); 
    for (auto i : primeCt){
        cout << i << " ";
    }
    cout << endl;
    solve(primeCt,A,2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration " << duration.count()<< endl;
    return 0;
}