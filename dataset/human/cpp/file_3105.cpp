#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin>>n;
    long long a[n],i,k=0,s=0;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<=n;i++)
    {
        if(a[i]<0)
        {a[i]=0-a[i];k++;}
    }
    if(k%2==0){
        for(i=1;i<=n;i++)
        s=s+a[i];
    }
    else {
        sort(a+1,a+n+1);
        for(i=2;i<=n;i++){
            s=s+a[i];
        }
        s=s-a[1];
    }
    cout<<s;
    return 0;
}
