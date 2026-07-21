#include<bits/stdc++.h>
using namespace std;

long long saisyou(long long a[],long long size){
  long long minv = INT_MAX;
  
  for (int i = 0;i<size;i++){
    if(a[i] < minv)
      minv = a[i];
  }

  return minv;

}


int main (){
  long long n;
  int i;
  cin >> n;

  long long a[n];
  long long ab[n];
  long long count = 0,sum = 0;

  for (i=0;i<n;i++){
    cin >> a[i];
    ab[i] = abs(a[i]);
    sum += ab[i];
    if (a[i] < 0)
      count += 1;
  }

  
  if (count%2 == 1)
    sum = sum - saisyou(ab,n)*2;

  cout << sum << endl;
}
