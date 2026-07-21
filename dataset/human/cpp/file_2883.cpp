#include <bits/stdc++.h>
using namespace std;

int main() {
  int Y=0;
  long X=0;
  int minx=1000000000;
  int N;
  cin>>N;
  
  vector<int> A(N);
for (int i = 0; i < N; i++) {
  cin >> A.at(i);
}
  
  for (int i = 0; i < N; i++) {
 // cout<< A.at(i)<<endl;
}
  
  for (int i = 0; i < N; i++) {
    if(A.at(i)>=0){
      X+=A.at(i);
     // cout<<X<<endl;
      minx=min(minx,A.at(i));
    }else{
      Y++;
      X+=A.at(i)*(-1);
      minx=min(minx,A.at(i)*(-1));
    }
  
}
  
  
 // cout<<X<<endl;
  
  if(Y%2==0){
  //  cout<<""<<endl;
    cout<<X<<endl;
  }else{
   // cout<<""<<endl;
    cout<<X-minx*2<<endl;
  }
 
}
