#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<long long> A(n);
  int mins = 0;
  long long sm = 0;
  for(int i = 0; n > i; i++){
    cin>>A[i];
    sm += abs(A[i]);
    if(A[i] < 0)mins++;
    A[i] = abs(A[i]);
  }
  sort(A.begin(),A.end());
  if(mins%2){
    sm -= A[0]*2;
  }
  cout << sm << endl;
}
