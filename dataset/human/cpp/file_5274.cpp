#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<double,double> Pdouble;

const int INF = 2000000000;

int main(){

  int n,r;
  cin >> n >> r;
  int answer;
  if(n < 10){
    answer= 100*(10-n);
    cout << answer+r << endl;
  }else{
    cout << r << endl;
    return 0;
  }
}
