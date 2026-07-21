#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long int A[N];
  int count = 0;
  long long int m=1000000000;
  long long int S=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]<0){
      count++;
    }
    m = min(m,abs(A[i]));
    S += abs(A[i]);
  }
  if(count%2 == 0){
    cout << S << endl;
  }
  else{
    cout << S-2*m << endl;
  }
}
