#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string a[n],b[m];
    bool flag=false;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){
            bool judge=true;
            for(int k=0; k<m; k++){
                for(int l=0; l<m; l++){
                    judge&=(a[i+k][j+l]==b[k][l]);
                    //cout<<a[i+k][j+l]<<endl;
                    //cout<<b[k][l]<<endl;
                }
            }
            if(judge){
                flag=true;
                goto escape;
            }
        }
    }
    escape:;
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }*/
    /*for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }*/
    return 0;
}
