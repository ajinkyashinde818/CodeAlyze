#include <bits/stdc++.h>

using namespace std;

vector<long int> a;
long int x,y;
long int sum;
long long int n;

int main(){
  long int temp;

  cin >> n;
  for( int i = 0; i < n; ++i){
    cin >> temp;
    a.push_back(temp);
  }
  sum = 0;
  for( auto i : a){
    sum += i;
  }
  x = 0;
  y = 0;
  long int min = 1000000000000000;
  for( int i = 0;  i < n-1; ++i){
    x += a[i];
    y = sum - x;
    if( min > labs(y-x) ){
      min = labs(y-x);
    }
  }
  cout << min << endl;
  
}
