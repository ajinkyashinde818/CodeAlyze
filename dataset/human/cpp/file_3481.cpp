#include "bits/stdc++.h"
using namespace std;


int main(){
    int n;
    cin>> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    
    long long ans = 0;
    int cnt=0;
    bool zeroflag = false;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            cnt++;
            a[i]*=-1;
        }else if(a[i]==0){
            zeroflag=true;
        }
    }
    if(zeroflag||cnt%2==0){
            //特にやることはなかった。全部正にできる
    }else{
        sort(a.begin(),a.end());
        a[0]*=-1;
    }
    for (int i = 0; i < n; i++)
    {
        ans +=a[i];
    }
    
    
    cout << ans <<endl;
    return(0);
}
