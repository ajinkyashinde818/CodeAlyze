#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<char>>b(m,vector<char>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>b[i][j];
            
    bool ans=false;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool flag=true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[k+i][l+j]!=b[k][l])
                        flag=false;
                }
            }
            if(flag)
                ans=true;
        }
    }

    ans?cout<<"Yes":cout<<"No";
    cout<<endl;

    return 0;
}
