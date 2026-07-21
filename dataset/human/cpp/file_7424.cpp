#include<bits/stdc++.h>
using namespace std;

int main(void){
  long long n, a[200010], sum=0, x=0, min=10000000000000000, y=0;
  cin >> n;
  for(int i=0;i<n;++i){
    cin >> a[i];
  	sum += a[i];
  }
  for(int i=0;i<n-1;++i){
    x += a[i];
    y = sum - x;
    long long tmp = abs(x-y);
    if(min > tmp) min = tmp;
  }
  cout << min << endl;
}
