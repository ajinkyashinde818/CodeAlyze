#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
  int N;
  cin>>N;
  int count=0;
  long int mn=10000000000;
  vector<long int> A;
  for(int i=0; i<N; ++i){
    long int a;
    cin>>a;
    if(a<0) count++;
    if(mn>abs(a)) mn=abs(a);
    A.push_back(abs(a));
  }
  
  long int ans=0;
  for(int i=0; i<N; ++i){
    ans+=A[i];
  }
  if(count%2==1) ans-=mn*2;
  
  cout<<ans<<endl;
}
