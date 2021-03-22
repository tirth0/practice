#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;

struct job{
    char jobId;
    int dead;
    int profit;
};

bool cmp(job a,job b){
    return a.profit>b.profit;
}

void scheduler(job arr[],int n){
    sort(arr,arr+n,cmp);
    int * result = new int[n];
    bool * slot = new bool[n];

    for (int i=0;i<n;i++){
        slot[i] = false;
    }

    for (int i=0;i<n;i++){

        for (int j=min(n,arr[j].dead)-1;j>=0;j++){

            if (!slot[j]){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i=0;i<n;i++){
        if (slot[i]) cout << arr[result[i]].jobId << " ";
    }
}

int main() 
{ 
    job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of jobs \n"; 
    
    // Function call 
    scheduler(arr, n); 
    return 0; 
} 