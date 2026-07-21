#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
  long int N;
  cin >> N;
  long int a[N];
  long long int nmin=9223372036854775807;
  long long int prediff=9223372036854775807;
  long long int allval=0;
  long long int left, right, diff;
  for(int i=0; i<N; i++){
    cin >> a[i];
    allval+=a[i];
  }

  left=0;
  for(int i=0; i<N-1; i++){
    left+=a[i];
    right=allval-left;
    diff = abs(left-right);
    //if(prediff<diff) break;
    if(diff<nmin){
      nmin = diff;
      prediff = diff;
    }
  }
  cout << nmin << endl;
}
