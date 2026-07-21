#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char a[n][n];
    char b[m][m];
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }   
    for(int i=0;i<m;i++){
        scanf("%s",b[i]);
    }
    int flag=0;
    for(int i=0;i<n&&flag==0;i++){
        for(int j=0;j<n&&flag==0;j++){
            int ia=i,ja=j;
            int ib=0,jb=0;
            while(a[ia][ja]==b[ib][jb]){
                if(ib==m-1&&jb==m-1){
                    flag=1;
                    break;
                }
                if(jb==m-1){
                    jb=0;
                    ib++;
                    ja=j;
                    ia++;
                }else if(jb<m-1){
                    jb++;
                    ja++;
                }
            }

        }
    }
 if(flag==1) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
 }
