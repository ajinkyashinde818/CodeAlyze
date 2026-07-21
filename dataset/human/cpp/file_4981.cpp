#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int       lint;
typedef vector<int>         vi;
typedef vector<lint>        vl;
typedef pair<int, int>      pii;
typedef vector<pii>         vii;
typedef set<int>            si;
typedef map<string, int>    msi;
 
#define pb(n)           push_back(n)
#define ALL(n)          (n.begin(), n.end())
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define M               10000000
#define MOD             10000007
#define INF             1e9+7
#define REP(i,a,b)      for(int i = int(a); i <= int(b); i++)
#define REPL(i,a,b)     for(lint i = lint(a); i <= lint(b); i++)
#define fastIO()        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    lint dr, inr, con;
    cin>>con>>dr;

    if(con >= 10) cout<<dr<<endl;
    else cout<<dr + (100 * (10 - con))<<endl;

    return 0;
}
