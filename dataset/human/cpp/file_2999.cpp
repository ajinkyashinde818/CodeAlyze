#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<cstdio>
#include<cmath>

using namespace std;
typedef long long ll;

ll n,a[100010]={0},cnt=0,m=1000000,s=0;
bool zr=false;

signed main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        m=min(m,abs(a[i]));
        if(a[i]<0){
            cnt++;
        }
        if(a[i]==0)zr=true;
        s+=max(a[i],-a[i]);
    }

    if(cnt%2==0||zr){
        cout<<s<<endl;
    }
    else{
        cout<<s-2*m<<endl;
    }



    return 0;
}
