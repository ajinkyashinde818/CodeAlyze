#include <bits/stdc++.h>
using namespace std;
const int INF = 1<< 28;
int main() {
  long long t,d;
  long long ta,tb;
  long long da,db;
  cin >> t >> d >> ta >> tb >> da >> db;
  long long sa = -1;
  long long amount = 0;
  for(int i = 0; i <= d;i+=da){
    for(int j = 0;j+i <= d;j+=db){
      if(i  == 0 && j == 0)continue;
      long long tmp = (ta*i + tb*j);
      long long tmp2 = i+j;
      if(sa == -1){
	sa = abs(tmp2*t - tmp);
	amount = tmp2;
      }
      if(sa*tmp2 > abs(tmp2*t-tmp)*amount){
	sa = abs(tmp2*t - tmp);
	amount = tmp2;
      }
    }
  }
  cout << fixed << setprecision(5) << (double)sa/(double)amount << endl;
  return 0;
}
