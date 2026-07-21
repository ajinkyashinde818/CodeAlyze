#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<int> A(n);
    int f=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(A[i]<0)f++;
    }
    int mi = 1e9;
    if(f%2==0){
        long long int ans = 0;
        for(int i=0;i<n;i++){
            if(A[i]<0)A[i]*=-1;
            ans += A[i];
        }
        cout<<ans<<endl;
    }
    else{
        long long int ans = 0;
        for(int i=0;i<n;i++){
            if(A[i]<0)A[i]*=-1;
            ans += A[i];
        }
        sort(A.begin(),A.end());
        ans -= A[0]*2;
        cout<<ans<<endl;
    }
}
