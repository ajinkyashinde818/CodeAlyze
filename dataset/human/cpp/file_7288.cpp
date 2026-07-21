#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std; 
const int MAXN=2e5+5;
long long a[MAXN],b[MAXN],ans=0;
int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        ans+=a[i];
    }
    long long cmin=1e10;
    for(int i=1;i<n;i++)
        if(cmin>abs(2*b[i]-ans)) cmin=abs(2*b[i]-ans);
    cout<<cmin<<endl;
    return 0;
}
