#include<iostream>
#include<cstring>
using namespace std;

//time complexity O(log(logn))

void sieveOfEratosthenes(int n){

    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2;p*p<=n;p++){
        if (prime[p]){
            for (int i=p;i<=n;i+=p){
                prime[i] = false;
            }

        }

    }

    for (int p=2;p<=n;p++){
        if(prime[p]) cout << p << " ";
    }
}

int main() 
{ 
    int n = 30; 
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl; 
    sieveOfEratosthenes(n); 
    return 0; 
} 