#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;
  m=0;
  vector<int> a,b;
  cin>>n;
  a.resize(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]<0)m++;
  }
  int min=0;
  if(m%2!=0){
  	for(int i=1;i<n;i++){
    	if(abs(a[i])<abs(a[min]))min=i;
  	}
  }
  for(int i=0;i<n-1;i++){
    if(a[i]<0&&m%2!=0&&i==min)continue;
    if(a[i]<0||(a[i]>0&&m%2!=0&&i==min)){
      a[i]*=-1;
      a[i+1]*=-1;
    }
  }
  long sum=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
  }
  cout<<sum<<endl;
  return 0;
}
