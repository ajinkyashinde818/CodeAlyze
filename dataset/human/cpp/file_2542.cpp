#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long N;
  long vec[100000];
  long count;
  long sum;
  long min;
  
  sum=0;
  count=0;
  cin >> N;
  
  for(long i=0; i<N; i++){
    cin >> vec[i];
    sum+=abs(vec[i]);
    if(vec[i]<=0)
      count++;
  }
  if(count%2==0)
    cout << sum << endl;
  else{
    min=abs(vec[0]);
    for(long j=1; j<N; j++){
      if(abs(vec[j])<min)
         min=abs(vec[j]);
    }
         sum=sum-2*min;
         cout << sum <<endl;
  }
}
