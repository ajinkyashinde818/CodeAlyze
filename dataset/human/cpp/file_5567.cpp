#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
int N,R;
int main(){
    int ans;
    cin >> N >> R;
    if ( N < 10){
        ans = R + 100*(10-N);
    } else {
      ans = R;
    }
    cout << ans << endl;
}
