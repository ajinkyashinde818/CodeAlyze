#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
long long ab(long long a,long long b){
 long long c=a-2*b;
 if(c>=0)
  return c;
 return -c;
 }
long long a[200010],n,mx,mx1,mx2,ans;
int main(){
cin>>n;
for(int i=0;i<n;i++){
 cin>>a[i];
 mx+=a[i];}
ans=10000000000;
for(int i=0;i<n-1;i++){
 mx1+=a[i];
 ans=min(ans,ab(mx,mx1));
 }
cout<<ans;
system("pause");
return 0;
}
