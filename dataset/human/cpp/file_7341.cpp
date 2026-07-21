#include<iostream>
using namespace std;

long long Abs(long long x){
  if(x < 0){
    return -x;
  }
  else{
    return x;
  }
}

int n;
long long a[200005], s[200005];

int main(void){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    s[i + 1] = a[i] + s[i];
  }
  long long m = Abs(2 * s[1] - s[n]);
  for(int i = 1; i < n; i++){
    m = min(m, Abs(2 * s[i] - s[n]));
  }
  cout << m << endl;
}
