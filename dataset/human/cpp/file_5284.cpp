#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, R;
  int in_rate, out_rate;
  
  cin >> N;
  cin >> R;
  out_rate=R;
  
  if(N>=10){
    in_rate=out_rate;
  }else{
    in_rate=out_rate+100*(10-N);
  }
  cout << in_rate << endl;
  
}
