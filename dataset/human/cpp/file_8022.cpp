#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long b[200010];
int main(){
    int c;
    cin>>c;
    long long s=0;
    for(int i=0;i<c;i++){
        cin>>a[i];
        if(i==0)
            b[i]=a[i];
        else
            b[i]=b[i-1]+a[i];//建数组b
        s=s+a[i];//求总
    }
    long long m;
    if(b[0]>s-b[0])
        m=b[0]+b[0]-s;
    else
        m=s-b[0]-b[0];//对m初始化
    for(int i=1;i<(c-1);i++){//每个人手里面必须有一张
        if(m>abs(s-b[i]-b[i]))
        m=abs(s-b[i]-b[i]);
    }
    cout<<m<<endl;
    return 0;
}
