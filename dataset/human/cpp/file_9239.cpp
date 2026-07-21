#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    char N[50][50], M[50][50];
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cin>>N[i][j];
        }
    }
    for(int i=0; i<m;i++){
        for(int j=0; j<m; j++){
            cin>>M[i][j];
        }
    }
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){
            bool ok=true;
            for(int k=i; k<i+m;k++){
                for(int l=j; l<j+m; l++){
                    if(N[k][l]!=M[k-i][l-j]){ok=false; break;}
                }
            }
            if(ok==true){cout<<"Yes"; return 0;}
        }
    }
    cout<<"No";
    return 0;
}
