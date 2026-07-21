#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
 
int main() {
  long N;
  cin >> N;
  vector<long>A(N);
  for(long i=0;i<N;i++){
    cin >> A.at(i);
  }
  long count=0;
  bool zero=false;
  for(long i=0;i<N;i++){
    if(A.at(i)<0){
      count++;
    }
    else if(A.at(i)==0){
      zero=true;
    }
  }
  long saisyou=1000000000;
  long long answar=0;
  if(count%2==0||zero){
    for(long i=0;i<N;i++){
      if(A.at(i)<0){
        answar+=-A.at(i);
      }
      else{
        answar+=A.at(i);
      }
    }
    cout << answar;
    return 0;
  }
  else{
    for(long i=0;i<N;i++){
        saisyou=min(saisyou,labs(A.at(i)));
    }
    for(long i=0;i<N;i++){
      if(A.at(i)<0){
      answar+=-A.at(i);
      }
      else{
        answar+=A.at(i);
      }
    }
    cout << answar-2*saisyou;
  }
}
