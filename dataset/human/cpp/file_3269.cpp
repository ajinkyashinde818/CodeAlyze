#include <bits/stdc++.h>
using namespace std;

int main(){
  long n,mi,ze,sum,li,lit;
  sum=0;
  cin >> n;
  vector<long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
    if(vec.at(i)<0){
      mi++;
      vec.at(i)=-vec.at(i);
    }
    else if(vec.at(i)==0){
      ze==1;
    }
  }
  li=vec.at(1);
  lit=1;
  if(ze==1){
    for (int j = 0; j < n; j++){
      sum += vec.at(j);
    }
  }
  else if(mi%2==0){
    for (int j = 0; j < n; j++){
      sum += vec.at(j);
    }
  }
  else if(mi%2==1){
    for (int j = 0; j < n; j++){
      if(vec.at(j)<li){
        li=vec.at(j);
        lit=j;
      }
    }
    vec.at(lit)=-vec.at(lit);
    for (int j = 0; j < n; j++){
      sum += vec.at(j);
    }
  }
  cout << sum << endl;
}
