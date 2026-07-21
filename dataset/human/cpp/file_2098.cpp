#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
  int n;
  cin >> n;
  cin.ignore();
  int a[n];
  int b[n];
  int nneg=0;
  long long ans=0;
  for(int i=0; i<n; i++){
  cin >> a[i];
  }
  for(int i=0; i<n; i++){
  b[i] = abs(a[i]);
  }
  sort(b, b+n, greater<int>());
  for(int i=0; i<n; i++){
  if(a[i]<0) nneg=nneg+1;
  }
  if((nneg%2)==0){
    for(int i=0; i<n; i++){
    ans=ans+b[i];
    }
  }else{
    for(int i=0; i<n-1; i++){
    ans=ans+b[i];
    }
    ans=ans-b[n-1];
  }
  cout <<ans; 
  return 0;
}
