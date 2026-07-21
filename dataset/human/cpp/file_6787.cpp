#include<bits/stdc++.h>
using namespace std;
long long a,b,n,A[500005],B[500005],fix[500005],l,r,l1,r1,l2,r2,l3,r3;
int main() {
    cin>>n;
    for(long long i=1;i<=n;i++) {
        cin>>A[i];
        fix[A[i]]++;
    }
    for(long long i=1;i<=n;i++) {
        cin>>B[i];
        fix[B[i]]++;
        if(fix[B[i]]>n) { a=1; }
    }
    if(a==1) { cout<<"No"; return 0; }
    cout<<"Yes"<<endl;
    reverse(B+1,B+1+n);
    for(long long i=1;i<=n;i++) {
        if(A[i]==B[i]) b=A[i];
    }
    if(b==0) {
        for(long long i=1;i<=n;i++) {
            cout<<B[i]<<" ";
        }
        return 0;
    }
    //cout<<b<<endl;
    
    for(long long i=1;i<=n;i++) {
        if(b==A[i] && l==0) l=i;
        if(b==A[i]) r=i;
    }
    for(long long i=1;i<=n;i++) {
        if(b==B[i] && l1==0) l1=i;
        if(b==B[i]) r1=i;
    }
    l2=max(l,l1);
    r2=min(r,r1);
    l3=min(l,l1);
    r3=max(r,r1);
    while(l2<=r2) {
        if(l3!=1) {
            l3--;
            swap(B[l3],B[l2]);
        }
        else {
            r3++;
            swap(B[r3],B[l2]);
        }
        l2++;
    }
    for(long long i=1;i<=n;i++) {
        cout<<B[i]<<" ";
    }
}
