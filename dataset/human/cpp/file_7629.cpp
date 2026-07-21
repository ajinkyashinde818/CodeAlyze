#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(void){
  long N;
  cin >> N;
  vector<long> neko;
  for(long i =0; i < N; i++){
    long a;
    cin >> a ;
    neko.push_back(a);
  }

  long sum = 0;

  for(auto it = neko.begin(); it != neko.end(); ++it){
    sum += *it;
  }

  long min = INT32_MAX;
  long now = 0;
  for(long i = 0; i < neko.size() -1; i++){
    now = now + neko[i];
    sum = sum - neko[i];
    long diff = abs(now - sum);
    //cout << diff << endl;
    if(diff < min ){
      min = diff;
    }
  }

  cout << min << endl;
  return 0;
}
