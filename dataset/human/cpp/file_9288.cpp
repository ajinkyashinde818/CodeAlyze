#include<iostream>
using namespace std;

char a[50][50+1],b[50][50+1];

bool search(int i,int j,int m){
    for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
            if(a[i+k][j+l]!=b[k][l])return false;
            if(k==m-1&&l==m-1)return true;
        }
    }
}
int main(){
    int n,m;  cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<=n-m;i++)for(int j=0;j<=n-m;j++)if(search(i,j,m)){cout<<"Yes"<<endl;return 0;}
    cout<<"No"<<endl;
    return 0;
}
