#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
  ll n,x,count=0,sum=0;
  cin >> n;
  ll a[n];
  bool havezero = false;
  for(int i=0;i<n;i++){
    cin >> x;
    a[i] = abs(x);
    if(x < 0){
      count++;
    }else if(x == 0){
      havezero = true;
    }
    sum += abs(x);
  }
  //cout << count << endl;
  if(havezero || count % 2 == 0){
    cout << sum;
  }else{
    sort(a,a+n);
    //cout << a[0] << endl;
    cout << sum - a[0] * 2;
  }
}
