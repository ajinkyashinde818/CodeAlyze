#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N,n,cnt;
  cin>>R>>G>>B>>N;
  while(N>=0){
    n=N;
    while(n>=0){
      if(n%G==0){
        cnt++;
      }
      n-=B;
    }
    N-=R;
  }
  cout<<cnt<<endl;
}
