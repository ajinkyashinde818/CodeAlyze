#include <iostream>
using namespace std;

int n;
long long a[200010];

int main(){
  cin >> n;
  cin >> a[0];
  long long tmp;
  for(int i = 1; i < n; i++){
    cin >> tmp;
    a[i] = tmp + a[i-1];
  }
  long long ans = 100100100100100100;
  for(int i = 0; i < n-1; i++)
    ans = min(ans, abs(2*a[i] - a[n-1]));
  cout << ans << endl;
  return 0;
}
