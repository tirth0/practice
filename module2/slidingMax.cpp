/*This program is an implementation of std::dequeue
The program prints the maximum element in each sliding
window of length K in a given array. The dequeue method 
takes O(n) time*/

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;



void printKMax(int arr[],int n,int k){
    //n is the length of array
    //k is length of sliding window
    deque<int> Qi(k);

    //Process first sliding window
    int i;
    for (i=0;i<k;i++){
        //remove smaller elements
        while((!Qi.empty() && arr[i]>=arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }


    for (;i<n;i++){
        //element at the front is the
        //largest in previous window
        cout << arr[Qi.front()] << " ";
        //Remove elements of current window
        while ((!Qi.empty()) && Qi.front() <= i - k)
        // Remove from front of queue
            Qi.pop_front(); 
        // Remove all elements 
        // smaller than the currently
        // being added element (remove 
        // useless elements)
        while ((!Qi.empty()) && arr[i] >=arr[Qi.back()])
            Qi.pop_back();
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
    // Print the maximum element 
    // of last window
    cout << arr[Qi.front()];
}

// Driver code
int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
} 