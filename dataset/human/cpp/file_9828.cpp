#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  char S[N];
  cin >> S;
  
  int a[26];
  for(int i = 0; i< 26; i++){
    a[i] = 0;
  }
  long sum = 1;
  for(int i = 0; i < N; i++){
    a[S[i] - 'a']++;
  }

  for(int i = 0; i < 26; i++){
    sum *= (1 + a[i]);
    sum %= 1000000007;
  }
  cout << sum - 1;
  return 0;
}
