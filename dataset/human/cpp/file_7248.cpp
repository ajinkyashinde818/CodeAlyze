#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
  int N;
  cin>>N;
  vector<long long> A(N,0);
  for(int i=0;i<N; i++){
    long long a;
    cin>>a;
    A[i]=a;
  }
  vector<long long> S(N+1,0);
  for(int i=0; i<N; i++) S[i+1]=A[i]+S[i];
  
  long long min=100000000000000;
  for(int i=1; i<N; i++){
    long long diff;
    diff=abs(S[i]-(S[N]-S[i]));
    if(diff<min){
      min=diff;
    }
  }
  cout<<min<<endl;
}
