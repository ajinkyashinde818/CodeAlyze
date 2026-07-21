#include<bits/stdc++.h>
using namespace std;

int main(){
long long a,b,c,n,ans=0;
cin>>a>>b>>c>>n;

for(int i=0;i<=n;i+=a)
for(int j=0;j<=n;j+=b){
if(i+j<=n)
if((n-(i+j)) % c == 0)
ans++; 
}

cout<<ans;
}
