#include <bits/stdc++.h> 
 
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<long, long> PLL;
 
//container util
//------------------------------------------
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
const double EPS=1e-10;
 
typedef int Weight;
//typedef
//------------------------------------------
 
typedef int Weight;
//typedef
//------------------------------------------
 
 
int main(){
    int N;cin>>N;
    long c=0;
    int tmp=1;
    while(1){
        if(tmp*(tmp-1)==2*N){
            c=tmp;break;
        }else if(tmp*(tmp-1)>2*N){
            break;
        }
        tmp++;
    }
    vector<long>used(N);
    if(c==0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        cout<<c<<endl;
        vector<vector<int>>res(c);
        int cnt=1;
        while(cnt<=N){
            REP(i,c){
                FOR(j,i+1,c){
                    res[i].PB(cnt);
                    res[j].PB(cnt);
                    cnt++;
                }
            }
        }
        REP(i,c){
            cout<<SZ(res[i]);
            for(auto r:res[i]){
                cout<<" "<<r;
            }
            cout<<endl;
        }
    }
    return 0;
}
