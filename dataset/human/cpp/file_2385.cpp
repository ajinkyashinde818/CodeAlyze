#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int minus=0;
  for (int i = 0; i < N; i++) {
    if(A.at(i)<0){
      minus++;
    }
  }
  long ans=0;
  int ch=A.at(0);
  if(minus%2==0){
    for (int i = 0; i < N; i++) {
      ans+=abs(A.at(i));
    }
  }
  
  else{
    for (int i = 1; i < N; i++) {
      ans+=abs(A.at(i));
      if(abs(ch)>abs(A.at(i))){
        ans+=abs(ch);
        
        ch=A.at(i);
        ans-=abs(ch);
      }
    }
    ans-=abs(ch);  
  } 
  cout<<ans<<endl;
}
