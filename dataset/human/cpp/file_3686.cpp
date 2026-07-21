#include <bits/stdc++.h>

using namespace std;


int main(){
  int N;
  cin >> N;

  int count = 0;
  vector<int64_t> a(N);
  vector<int64_t> ab(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
    if(a[i] < 0){
      count++;
    }
  }

  int64_t result = 0;
  for(int i=0;i<N;i++){
    if(a[i] < 0){
      ab[i] = -1*a[i];
      result += -1*a[i];
    }
    else {
      ab[i] = a[i];
      result += a[i];
    }
  }
  
  if(count%2 == 0){
    cout << result << endl;
  }
  else{
    result -= (*min_element(ab.begin(),ab.end()))*(2);
    cout << result << endl;
  }
  return 0;
}
