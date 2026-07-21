#include <bits/stdc++.h>
using namespace std;

long long int min(long long int a, long long int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

long long int p(long long int a){
    if(a<0){
        a=-a;
    }
    return a;
}

int main()
{
    int n;
    long long int sum=0,ans=1000000000;
    long long int a[200000];
    long long int sm[200000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
        sm[i]=sum;
    }
    for(int i=0;i<n-1;i++){
        ans=min(ans,p(sm[i]*2-sum));
    }
    if(n==2){
        ans=p(a[0]-a[1]);
    }
    cout << ans << endl;
    return 0;
}
