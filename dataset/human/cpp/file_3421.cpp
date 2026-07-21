#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long A[100010];
    long long counter=0;
    long long b=1000000010;
    long long sum=0;
    for(long long i=0; i<N; i++){
        long long a;
        cin>>a;
        if(a<0) counter++;
        b=min(b,abs(a));
        sum+=abs(a);
        A[i]=a;
    }
    if(counter%2==0) cout<<sum<<endl;
    else cout<<sum-2*b<<endl;
}
