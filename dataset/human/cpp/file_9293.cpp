#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int masu[100001];
int main(){
    int m,n;
    cin>>n>>m;
    
    char a[n][n];
    char b[m][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            
            bool flag=0;
            for(int k=i;k<i+m;k++){
                for(int l=j;l<j+m;l++){
                    if(a[k][l]!=b[k-i][l-j]){
                        flag=1;}
                }
            }
            if(flag==0){
                cout<<"Yes"<<endl;return 0;}
    }
    }
    
    cout<<"No"<<endl;
    
    return 0;
}
