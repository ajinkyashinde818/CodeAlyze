#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <long long> b(n);
  int count = 0;
  int flag = 1;
  for (int i = 0; i < n; i++){
    cin >> b.at(i);
    if (b.at(i) < 0){
      count ++;
    }
    else if (b.at(i) == 0){
      flag = 0;
    }
    b.at(i) = labs(b.at(i));
  }
  flag = count % 2 * flag;
  long long ans = 0;
  for (int i = 0;i<n;i++){
    ans += b.at(i);
  }
  if (flag == 1){
    int min =  *min_element(b.begin(), b.end());
    ans -= 2*min;
  }
  cout << ans << endl;
}
