// Bismillahirahmanirahim
  #include <bits/stdc++.h>
  using namespace std;






int main() {
  int n;
  cin >> n;
  long long values[n];
  for(int i = 0; i< n; i++) cin >> values[i];
  int eksiler = 0;
  long long res = 0;
  int ind;
  long long larges = 1000000001;
  for(int i = 0; i < n;i++) {
    if(values[i] < 0) eksiler++;
    if(abs(values[i]) < larges) {larges = abs(values[i]);ind = i;}
  }

  if(eksiler%2 == 0) {
    for(int i = 0; i < n;i++) res += abs(values[i]);
  }
  else{
    if(values[ind] < 0) {
      for(int i = 0; i < n;i++) res += abs(values[i]);
      res += 2*values[ind];
    }
    else {
      for(int i = 0; i < n;i++) res += abs(values[i]);
      res -= 2*values[ind];
    }
  }
  cout << res;


}
