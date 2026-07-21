#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC50(void);
void ABC51(void);
void ABC52(void);
void ABC53(void);
void ABC54(void);
void ABC55(void);
void ABC56(void);
void ABC57(void);
void ABC58(void);
void ABC59(void);

int main(void){
    ABC54();
}

void ABC54(){
    int n,m,ans=0,i,j,k,l,count=0;
    cin>>n>>m;
    char a[n][n],b[m][m];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    //Bの左上を指定
    for(i=0;i<=n-m;i++){
        for(j=0;j<=n-m;j++){
            //Bの画像とAの画像を比較
            for(k=0;k<m;k++){
                for(l=0;l<m;l++){
                    if(b[k][l]==a[i+k][j+l])count++;
                }
            }
            if(count==m*m)ans=1;
            count=0;
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
