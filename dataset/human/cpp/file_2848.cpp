#include<iostream>

using namespace std;

int main(){
  int n, i = 0,count = 0;
  long int num[100000];
  long int ans = 0, l, min = -1;
  cin >> n;
  while(i < n){
    cin >> l;
    num[i] = l;
    i++;
  }
  i = 0;
  while(i < n){
    if(num[i] < 0){
      count++;
      num[i] = -1 * num[i];
    }
    if(min > num[i] || min == -1){
      min = num[i];
    }
    ans += num[i];
    i++;
  }
  if(count % 2 == 1){
    ans -= 2 * min;
  }
  cout << ans << endl;
}
