#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[100000];
  int numm = 0;
  int zflag = 0;
  int min = 1000000000;
  long long sum = 0;
  for(int i = 0; i < n ; i++){
    cin >> a[i];
    int aai = abs(a[i]);
    sum += aai;
    if(min > aai) min = aai;
    if(a[i] < 0) numm++;
    else if(a[i] == 0) zflag = 1;
  }
  if(zflag || numm%2 == 0) cout << sum << endl;
  else{
    cout << sum - 2*min << endl;
  }
}
