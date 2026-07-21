#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  long sum = 0;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  int minus;
   for (int i = 0; i < N; i++){
     if(A.at(i) < 0){minus++;}
   }
  

    for (int i = 0; i < N; i++){
      if(A.at(i) < 0){ 
        sum -= A.at(i);
        A.at(i) = -A.at(i);
      } else { sum += A.at(i);}
    }

  if (minus % 2 == 0){
    cout << sum << endl;
  } else {
    int minA = min(A.at(0), A.at(1));
    for (int i = 0; i < N; i++){
      minA = min(minA, A.at(i));
    }
    cout << sum - 2*minA << endl;}
      
  
}
