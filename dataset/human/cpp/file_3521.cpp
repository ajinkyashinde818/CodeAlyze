#include<iostream>
#include<algorithm>
#include<string>
#include<numeric>
#include<vector>
using namespace std;

int gcd(int a,int b){
  if (a%b==0) return b;
  else return gcd(b,a%b);
}

int main(){
  int n;
  cin >> n;
  long long a[n];
  int count = 0;
  long long ans=0;
  for (int i=0;i<n;i++){
    cin >> a[i];
    if (a[i] < 0) count += 1;
    a[i] = abs(a[i]);
    ans += a[i];
  }
  sort(a,a+n);
  if (count%2==0) cout << ans << endl;
  else cout << ans - 2*a[0] << endl;
  return 0;
}
