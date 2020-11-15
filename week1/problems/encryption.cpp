#include <bits/stdc++.h>

using namespace std;
//hackerrank encryption problem, boilerplate by hackerrank
// Complete the encryption function below.
string encryption(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int n = str.length();
    int row = (int)floor(sqrt(n)), col = (int)ceil(sqrt(n));
    while (row*col < n){
        if (row<col) row++;
        else col++;
    }
    cout << row << " " << col<< endl;
    string result = "";int k=0;
    char a[row][col];
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (k<n){
                a[i][j] = str[k++];
            }
            else a[i][j] = '$';
        }
    }
    for (int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            if (a[j][i]!='$') result+= a[j][i];
            cout << a[i][j] << " ";
        }
        cout << endl;
        result += " ";
    }
    return result;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
