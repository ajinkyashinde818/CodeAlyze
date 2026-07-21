#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int r,g,b,n,count=0;
cin >>r >>g>>b>>n;
for(long long int i=0;i<=n/r;i++){
for(long long int j=0;j<=(n-i*r)/g;j++){
if((n-r*i-g*j)%b==0 && (n-r*i-g*j)>=0){
count++;
}
}
}
cout <<count<<endl;
}
