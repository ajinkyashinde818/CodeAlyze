#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N;
  cin>>N; 
  vector<int> a(N);  
  for(int j=0; j<N;j++){
    cin>>a.at(j);
  }
  
  
  long to=0;
  for(int i=0; i<N-1;i++){
    to+=a.at(i);
  }
  to-=a.at(N-1);
  long ans=abs(to);
  for(int i=N-2; i>0;i--){
    ans=min(ans,abs(to-2*a.at(i)));
    to-=2*a.at(i);
  }
   
  cout<<ans<<endl;
}
