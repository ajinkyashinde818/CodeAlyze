#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> a;
    vector<string> b;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<m;i++){
        string t;
        cin>>t;
        b.push_back(t);
    }
    int ans=0;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        k=l=114514;
                    }
                    if(k+1==m&&l+1==m){
                        ans++;
                    }
                }
            }
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
