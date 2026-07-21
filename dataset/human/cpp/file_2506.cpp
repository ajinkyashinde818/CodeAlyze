#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
int main() {
  int N,i,c;
  c=0;
  long sum;
  sum=0;
  cin>>N;
  int A[N];
  int B[i];
  for(i=0;i<N;i++){
  cin>>A[i];
    if(A[i]<0) c++;
  B[i]=abs(A[i]);
  }
  sort(B,B+N);
  if(c%2==0){
  for(i=0;i<N;i++){
  sum=sum+B[i];
  }
  }else{
    for(i=1;i<N;i++){
  sum=sum+B[i];
  }
   sum=sum-B[0];
  }
  
cout<<sum<<endl;
}
