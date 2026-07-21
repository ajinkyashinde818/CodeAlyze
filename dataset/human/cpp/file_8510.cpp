#include <bits/stdc++.h>
using namespace std;
int check(vector<string> a, vector<string> b, int x, int y){
    int flag = 0, m = b.size(); int cnt = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            if (a[x+i][y+j]!=b[i][j]){
                flag = 1;
                break;
            }
        }
        if (flag == 1)break;
    }
    if (flag == 1)return 0;
    return 1;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<string> a(n), b(m);
    for (int i=0; i<n; i++)cin>>a[i];
    for (int i=0; i<m; i++)cin>>b[i];
    int flag = 0;
    for (int i=0; i<=n-m; i++){
        for (int j=0; j<=n-m; j++){
            int x = check(a, b, i, j);
            if (x == 1){
                flag = 1;
                break;
            }
        }
        if (flag == 1)break;
    }
    if (flag == 0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
