#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  int N = n;
  vector<long int> a;
  for(int i = 0;i < n;i++){
    long int p;
    cin >> p;
    a.push_back(p);
  }

  sort(a.begin(),a.end());
  int i = 0;
  int count = 0;
  for(i = 0;i < n;i++){
    if(a[i] < 0){
      count++;
      a[i] = a[i]*(-1);
    }
  }
  sort(a.begin(),a.end());
  long int ans = 0;
  if(count%2 == 0){
    for(int j = 0;j < n;j++){
      ans += a[j];
    }
  }
  else{
    ans -= a[0];
    for(int j = 1;j < n;j++){
      ans += a[j];
    }
  }
  cout << ans << endl;
}
