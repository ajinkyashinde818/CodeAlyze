#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000+5;
int data[maxn]={0};
typedef long long ll;

int main()
{
    ll sum=0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>data[i];
        sum+=data[i];
    }
    ll num=data[0];
    ll cnt=0;
    ll ans=0;
    ll tmp=num;
    ll cnt1=sum-tmp;
    ans=abs(tmp-cnt1);
    for(int i=1;i<N-1;i++){
        tmp=num;
        cnt1=sum-tmp;
        num+=data[i];
        cnt=sum-num;
        if(ans>abs(num-cnt)){
            ans=abs(num-cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
