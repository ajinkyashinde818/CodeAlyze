#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int main(){
    int n;
    cin>>n;
    int minn=0x3f3f3f3f;
    int id=0;
    int sum1=0,sum2=0;
    long long  ans=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]>0) sum1++;
        if(a[i]<0) sum2++;
        ans+=abs(a[i]);
        minn=min(abs(a[i]),minn);
    }
    // printf("%d %d %d\n",sum1,sum2,ans);
    if(sum2%2==0) cout<<ans<<endl;
    else cout<<ans-2*minn<<endl;
    //system("pause");
}
