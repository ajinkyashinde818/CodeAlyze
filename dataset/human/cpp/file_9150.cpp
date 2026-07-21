#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char a[n+1][n+1];
    char b[m+1][m+1];
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
     for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
        cin>>b[i][j];
    }
     /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<a[i][j];
        cout<<endl;
    }
     for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
        cout<<b[i][j];
            cout<<endl;
    }*/
    int flag=0;
    for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
        flag=0;
        for(int s=0,k=i;s<m;s++,k++){
            for(int t=0,d=j;t<m;t++,d++){
                if(b[s][t]!=a[k][d]){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    }
    cout<<"No"<<endl;
}
