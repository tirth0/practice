#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

void simpleSieve(vector<int> &prime, int limit){
    bool isPrime[limit+1];
    memset(isPrime, true, sizeof(isPrime));

    for (int p=2;p*p<=limit;p++){
        if(isPrime[p]){
            for (int i=p*p; i<=limit;i+=p){
                isPrime[i] = false;
            }
        }
    }
    for (int p=2;p<=limit;p++){
        if (isPrime[p]){
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

void segmentSieve(int n){

    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(prime, limit);

    int low = limit;
    int high = 2 * limit;

    while(low<n){
        if (high>=n) high = n;

        bool isPrime[limit+1];
        memset(isPrime,true,sizeof(isPrime));    
        for (int i=0;i<prime.size();i++){

            int loLim = floor(low/prime[i])*prime[i];
            if (loLim < low){
                loLim += prime[i];
            }

            for (int j=loLim; j<high; j+=prime[i])
                isPrime[j-low] = false;
        }
        for (int i = low;i<high;i++)
            if (isPrime[i-low]) cout << i << " ";

        low = low+limit;
        high = high +limit;
    }

}


    int main(){
    int n = 1000;
    cout << "Primes smaller than " << n << ":n";
    segmentSieve(n);
    return 0;
}
