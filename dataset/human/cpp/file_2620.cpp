#include <iostream>
#include<algorithm>
#include <stdio.h>
#include <string>
#include <map>
//#include <bits/stdc++.h>
using namespace std;
/*inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}*/
typedef long long ll;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
long long a[100004],b[100004],k[1000001];
int main() {
    int n,x;
    while(cin>>n)
    {
        long long ans=0,mi=9999999,k=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ans+=abs(a[i]);
            if(a[i]<0)
                k++;
            mi=min(mi,abs(a[i]));
        }
        if(k%2==0)
            cout<<ans<<endl;
        else
            cout<<ans-2*mi<<endl;
    }
    return 0;
}
