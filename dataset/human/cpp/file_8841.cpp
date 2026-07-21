#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
    cin >> n >> m;
    char array[n][n];
    for(int i = 0;i < n;i++){
        string str;
        cin >> str;
        for(int j = 0;j < n;j++){
            array[i][j] = str[j];
            //cout << array[i][j] << i << j << endl;
            }
    }
    char match[m][m];
    for(int i = 0;i < m;i++){
        string str;
        cin >> str;
        for(int j = 0;j < m;j++)
            match[i][j] = str[j];
    }
    for(int i = 0;i < n - m + 1;i++){
    for(int j = 0;j < n - m + 1;j++){
        bool flag = true;
        for(int k = 0;k < m;k++){
        for(int r = 0;r < m;r++){
            if(match[k][r] != array[i + k][j + r])flag = false;
            //cout << i << j << k << r;
        }
    }
    if(flag){
        cout << "Yes";
        return 0;
    }
    }
}
        cout << " No";
        return 0;
    }
