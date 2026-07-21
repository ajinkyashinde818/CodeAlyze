#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <tuple>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define DECIM8  fixed<<setprecision(8) 
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

using namespace std;
double temp(int at,int ac,int bt,int bc)
{
  return (double)(at*ac+bt*bc)/(double)(ac+bc);
}
bool suit(int ac,int bc,int d)
{
  return (1<=(ac+bc) && (ac+bc)<=d);
}
int main(void)
{
  int t,d,at,bt,ad,bd;
  cin >> t >> d;
  cin >> at >> bt;
  cin >> ad >> bd;
  double answer=1000.0;
  REP(i,d/ad+1) REP(j,d/bd+1){
    int ac=ad*i,bc=bd*j;
    if(suit(ac,bc,d)){
      answer=min(answer,abs(temp(at,ac,bt,bc)-t));
    }
  }
  cout << answer << endl;
  return 0;
}
