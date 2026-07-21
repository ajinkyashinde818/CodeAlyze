#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  int cnt = 0;
  ll sum = 0LL;
  ll a[N];
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum += abs(a[i]);
    if(a[i] < 0) cnt++;
    a[i] = abs(a[i]);
  }

  if(cnt % 2 == 0){
    cout << sum << endl;
  }
  else{
    cout << sum - *min_element(a, a+N) * 2 << endl;
  }

  return 0;


}
