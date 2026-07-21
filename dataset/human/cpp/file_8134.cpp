#include<bits/stdc++.h>
using namespace std;

long long a[200010];

long long retabs(long long x,long long y){
    if(x>y)return x-y;
    else return y-x;
}

int main(){
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(i>0){
            a[i]+=a[i-1];
        }
    }
    long long min=retabs(a[0],sum-a[0]);
    for(int i=1;i<n-1;i++){
        if(min>retabs(a[i],sum-a[i]))min=retabs(a[i],sum-a[i]);
    }
    cout<<min<<endl;
    return 0;
}
