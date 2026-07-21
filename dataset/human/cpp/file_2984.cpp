#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;//政府の判定
  int c;//最少
  long int t;//和
  int n;
  int i;
  b=1;
  t=0;
  c=1000000000;
  cin >>n;
  for (i=0; i<n; i++){
    cin >>a;
    if(a<0){
      	b=(-1)*b;
    }
      
    if(a<0){
      a=a*(-1);
    }
    t=t+a;
    if(a<c){
      c=a;
    }
  
  }
  if(b<0){
    t=t-2*c;
  }
  cout<<t;
}
