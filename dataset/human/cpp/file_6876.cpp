#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N+1);
  vector<int>B(N+1);
  vector<int>C(N);
  vector<int>D(N);
  for(int i=0;i<N;i++){
    cin>>C[i];
    A[C[i]]++;
  }
  for(int i=0;i<N;i++){
    cin>>D[i];
    B[D[i]]++;
  }
  for(int i=1;i<N+1;i++){
    if(A[i]+B[i]>N){
      puts("No");return 0;
    }
  }
  puts("Yes");
  for(int i=0;i<N;i++){
    A[i+1]+=A[i];
    B[i+1]+=B[i];
  }
  int count=0;
  for(int i=0;i<N;i++)count=max(count,A[i+1]-B[i]);
  for(int i=0;i<N;i++)cout<<D[(i+N-count)%N]<<(i!=N? " ":"");
  cout<<"\n";
}
