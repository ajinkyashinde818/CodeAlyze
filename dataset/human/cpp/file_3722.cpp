#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    long long int N;
    cin>>N;
    long long int mincou=0,minabs=2100000000;
    long long int ans=0;
    for(int i=0;i<N;i++){
        long long int a;
        cin>>a;
        if(a<0)mincou++;
        minabs=min(minabs,abs(a));
        ans+=abs(a);
    }
    if(mincou%2==0)cout<<ans<<endl;
    else cout<<ans-2*minabs<<endl;
    return 0;
}
