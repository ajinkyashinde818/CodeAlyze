#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A;
  long sumy=0;
  for(int i=0; i<N; i++){
    int a; cin >> a;
    sumy+=a;
    A.push_back(a);
  }
  long min = 1e15;
  long sumx =0;
  for(int i=0; i<N-1; i++){
    sumx+=A[i];
    sumy-=A[i];
    if(abs(sumx-sumy)<min){
      min=abs(sumx-sumy);
    }
  }
  cout << min << endl;
  return 0;
}
