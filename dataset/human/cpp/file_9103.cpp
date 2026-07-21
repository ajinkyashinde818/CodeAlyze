#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,ans = 0;
    cin >> n >> m;
    char a[n][n],b[m][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)cin >> a[i][j];
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++)cin >> b[i][j];
    }
    int check = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++,ans = 0){
            if(i+m-1 >= n && j+m-1 >= n)continue;
            for(int p = 0;p < m;p++){
                for(int q = 0;q < m;q++){
                    if(b[p][q] != a[i+p][j+q])++ans;
                }
            }
            if(ans == 0)check = 0;
        }
    }
    if(check == 0)cout << "Yes";
    else cout << "No";
    return 0;
}
