#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  long long n,a[1000000],min,x=0,y=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i==0)x+=a[i];
    else y+=a[i];
  }
  min=abs(x-y);
  for(int i=1;i<n-1;i++){
    x+=a[i];
    y-=a[i];
    if(min>abs(x-y))min=abs(x-y);
  }
  cout<<min;
  return 0;
}
