#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
int main() {
  int R,G,B,N,i,j,k;
  cin>>R>>G>>B>>N;
  int a,sum;
  a=0;
  sum=0;
  for(i=0;;i++){
    if(R*i>N) break;
  for(j=0;;j++){
    sum=R*i+G*j;
    if(sum>N) break;
    if((N-sum)%B==0){
    a++;
      
    }
    
  
  }
  }
  cout<<a<<endl;
}
