#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  
  int N;
  cin >> N;
  long A[N];
  bool flag = false;
  int count = 0;
  for(int i=0;i<N;i++){
      cin >> A[i];
      if(A[i]==0){
        flag = true;
      }
      if(A[i]<0){
        count++;
      }
  }

  long ans = 0;
  for(int i=0;i<N;i++){
    ans += abs(A[i]);
  }

  if(flag || count%2==0){
    cout << ans <<endl;
  }else{
    vector<long> absolute; 
    for(int i=0;i<N;i++){
      long l = abs(A[i]);
      absolute.push_back(l);
    }
    sort(absolute.begin(), absolute.end());
    ans -= 2*absolute[0];
    cout << ans <<endl;
  }
  
  return 0;
}
