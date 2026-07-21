#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,m;
    cin>>n>>m;
    string a[55],b[55];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool flag=true;
            for(int k=i;k<i+m;k++){
                if(a[k].substr(j,m)!=b[k-i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
