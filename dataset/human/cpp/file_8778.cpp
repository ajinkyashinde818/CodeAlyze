#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    bool c=true;
    char x[a][a],y[b][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)cin>>x[i][j];
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++)cin>>y[i][j];
    }
    for(int i=0;i<=a-b;i++){
        for(int j=0;j<=a-b;j++){
            c=true;
            for(int k=0;k<b;k++){
                for(int l=0;l<b;l++){
                    if(x[i+k][j+l]!=y[k][l])c=false;
                }
            }
            if(c){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
