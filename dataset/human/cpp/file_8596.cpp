#include <iostream>
using namespace std;
int main(void){
    int n,m;
    char a[51][51],b[51][51];
    
    cin>>n>>m;
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
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            int  s=1;
            for(int k=0;k<m&&s;k++){
                for(int l=0;l<m&&s;l++){
                    if(a[i+k][j+l]!=b[k][l])s=0;
                }
            }
            if(s==1){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;
}
