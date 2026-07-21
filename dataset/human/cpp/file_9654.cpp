#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<char>>b(m,vector<char>(m));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)cin>>b[i][j];
    for(int i=0;i+m<=n;i++){
        for(int j=0;j+m<=n;j++){
            bool match=1;
            for(int k=0;k<m;k++)for(int l=0;l<m;l++)if(a[i+k][j+l]!=b[k][l])match=0;
            if(match){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
