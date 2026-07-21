#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
string a[MAXN],b[MAXN];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int flag2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int flag = 0;
            for(int k=0;k+i<n&&k<m;k++){
                for(int t=0;t+j<n&&t<m;t++){
                    if(a[k+i][j+t]==b[k][t])
                        flag ++;
                }
            }
            if(flag == m*m)
                flag2 = 1;
        }
    }
    if(flag2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
