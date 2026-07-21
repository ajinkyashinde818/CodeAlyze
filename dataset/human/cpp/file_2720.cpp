#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n+10];

  bool flag = false;
  bool even = true;
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    if(a[i] < 0){
      cnt++;
      a[i] = abs(a[i]);

    }
  }
  if(cnt % 2 == 0){
    long long int sum = 0;
    for(int i = 1; i <= n; i++)sum += a[i];
    cout << sum <<endl;
    return 0;
  }else if(cnt % 2 != 0){
    sort(a+1, a+n+1);
    long long int sum = 0;
    for(int i = 2; i <= n; i++)sum += a[i];
    cout << sum - a[1] <<endl;
    return 0;
  }


  
}
