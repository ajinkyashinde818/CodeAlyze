#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long m=9999999999;
  long long answer=0;
  int judge=0;
  for(int i=0;i<N;i++){
    long long A;
    cin>>A;
    answer+=abs(A);
    if(A<0) judge++;
    if(abs(A)<m) m=abs(A);
  }
  if(judge%2==0) cout<<answer<<endl;
  else cout<<answer-2*m<<endl;
  
  return 0;
}
