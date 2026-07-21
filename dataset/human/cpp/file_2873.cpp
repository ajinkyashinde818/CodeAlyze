#include <bits/stdc++.h>
using namespace std;

long long A[100100];
int main(){
    int n; scanf("%d",&n);
    long long sum1=0,sum=0;
    int odd=0,p=0;
    int o=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&A[i]);
        if(A[i]==0 && o==1) odd++,o=0;
        if(A[i]<0) odd++,o=1;
        sum += abs(A[i]);
//        cout<<sum<<endl;
    }
    if(odd % 2 == 0) {
        cout<<sum<<endl;
    }
    else {
        long long z=10000000000000;
        int p=0;
        for(int i=1;i<=n;i++) {
            if(A[i]<0) {
                p=i; break;
            }
        }

        for(int i=1 ;i<=n;i++) {
            if(abs(A[i])<z) z=abs(A[i]);
        }
        cout<<sum-(z*2)<<endl;
    }
    return 0;
}


/*
test9
*/
