#include <bits/stdc++.h>
using namespace std;


int main() {
 int N,count=0,m;
  long long sum=0;
  cin >> N;
  vector<int>vec(N);
  
  for(int i=0;i<N;i++){
    cin >> vec.at(i);
    sum+=abs(vec.at(i));
    if(vec.at(i)<0)count++;
  }
  
  m=vec.at(0);
  
  for(int i=0;i<N-1;i++){
    m=min(abs(m),abs(vec.at(i+1)));
  }
  
  if(count%2==0){
    cout<<sum<<endl;
  }
  else{
    cout<<sum-2*m<<endl;
  }
  
}
