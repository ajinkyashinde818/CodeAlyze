#include <vector> 
#include <list> 
 #include <map>
 #include <set>
#include <deque>
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
#include <queue>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
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

//debug
#define dump(x)  cerr << #x << '=' << (x) << endl;
#define debug(x) cerr << #x << '=' << (x) << '('<<'L' << __LINE__ << ')' << ' ' << __FILE__ << endl;

int main(){
    int M,N;
    vector< string> As,Bs;
    string A,B;
    cin>>N>>M;
    REP(i,N){
        cin>>A;
        As.push_back(A);
    }
    REP(i,M){
        cin>>B;
        Bs.push_back(B);
    }

    REP(k,As.size()-Bs.size()+1){//縦の開始点
        REP(j,As[0].size()-Bs[0].size()+1){//横の開始点
            cerr<<"開始点;"<<k<<" "<<j<<endl;
            REP(i,M){
                string sub=As[k+i].substr(j,Bs[0].size());
                debug(sub);
                if(sub!=Bs[i]){
                    goto NEXT;
                }
            } 

            cout<<"Yes"<<endl;
            exit(0);
            NEXT:;
        }
    }
    cout<<"No"<<endl;





}
