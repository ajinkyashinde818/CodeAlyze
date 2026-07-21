#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,negative = 0;
  cin >> n;
  long a[n],result = 0,x = 1000000000000000;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    result += abs(a[i]);
    x = min(x,abs(a[i]));
    if(a[i] <= 0){
      negative++;
    }
  }
  if(negative % 2 == 1){
    result -= 2*x;
  }
  cout << result << endl;
}
