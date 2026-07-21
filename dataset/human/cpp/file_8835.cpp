#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    int a[n][n],b[m][m];
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<n;++j){
            if(s[j]=='#')a[i][j]=1;
            else a[i][j]=0;
            
//            cout<<a[i][j];
        }
//            cout<<endl;
    }

    for(int i=0;i<m;++i){
        cin>>s;
        for(int j=0;j<m;++j){
            if(s[j]=='#')b[i][j]=1;
            else b[i][j]=0;

//            cout<<b[i][j];
        }
//            cout<<endl;
    }
    int ans=0;

    for(int i=0;i<n-m+1;++i){
        for(int j=0;j<n-m+1;++j){
        if(a[i][j]==b[0][0]){
            int tmp=0;
            for(int k=0;k<m;++k){
                for(int l=0;l<m;++l){
                    if(b[l][k]==a[i+l][j+k])tmp++;
            }
        }
        if(tmp==m*m){
            cout<<"Yes"<<endl;
            return 0;
        }
        }
        }
    }
    cout<<"No"<<endl;
	return 0;
}
