#include <bits/stdc++.h>

using namespace std;
//method code from hackerrank balls in a container
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {

    vector <int> contCap(container.size(),0),ballTypeCap(container.size(),0);
    int k=0;
    for (int i=0;i<container[0].size();i++){
        for (int j=0;j<container[0].size();j++){
            contCap[k] += container[i][j];
            ballTypeCap[k] += container[j][i];
        }
        k++;
    }
    sort(contCap.begin(),contCap.end());
    sort(ballTypeCap.begin(),ballTypeCap.end());
    if (contCap == ballTypeCap) return "Possible";
    return "Impossible";
}
