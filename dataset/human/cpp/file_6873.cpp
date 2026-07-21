#include <iostream>
#include <fstream>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <cstring>
#include <sstream>
#include <complex>

#define f first
#define s second
#define ll long long
#define ld double
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define y0 eto
#define y1 mezhdy
#define y2 nami
#define left extermination
#define right dismemberment
 
using namespace std;
 
double start_moment = 0;
double get_runtime() { return 1.0*clock()/CLOCKS_PER_SEC; }
void reset_timer() { start_moment = get_runtime(); }
double timer_time() { return get_runtime() - start_moment; }
void runtime(){cout<<fixed<<setprecision(5)<<get_runtime()<<'\n';}
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
template <class T>void read(vector<T> &a,ll n){T x; a.clear();for(ll i=0;i<n;i++){cin>>x;a.pb(x);}}
template <class T>void write(vector<T> &a){for(T x : a) cout<<x<<' ';cout<<'\n';}

const int N=200005;

int n;
vector<int> a,b;

vector<int> pos[N];
map<int,int> in_a,in_b;

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("INPUT.txt","r",stdin);
//    freopen("OUTPUT.txt", "w", stdout);
    
    cin>>n;
    read(a,n);
    read(b,n);
    
    for(int i=0;i<a.size();i++)
        pos[a[i]].pb(i);
    
    
    vector<pii> c1,c2;
    
    int cnt=1;
    for(int i=1;i<a.size();i++)
        if(a[i]==a[i-1])
            cnt++;
        else
        {
            c1.pb(mp(cnt,a[i-1]));
            cnt=1;
        }
    c1.pb(mp(cnt,a.back()));
    
    cnt=1;
    for(int i=1;i<b.size();i++)
        if(b[i]==b[i-1])
            cnt++;
        else
        {
            c2.pb(mp(cnt,b[i-1]));
            cnt=1;
        }
    c2.pb(mp(cnt,b.back()));
    
    
    for(int i=0;i<c1.size();i++)
        in_a[c1[i].s]=c1[i].f;
    for(int i=0;i<c2.size();i++)
        in_b[c2[i].s]=c2[i].f;

    for(int i=0;i<a.size();i++)
        if(in_a[a[i]]+in_b[a[i]]>n)
        {
            cout<<"No\n";
            return 0;
        }
    
    vector<int> tipa_a(n,-1),tipa_b(n,-1);
    
    sort(all(c1));
    reverse(all(c1));
    
    int pos1=0;
    int pos2=0;
    
    for(int i=0;i<c1.size();i++)
    {
        for(int j=0;j<in_a[c1[i].s];j++)
        {
            tipa_a[pos1]=c1[i].s;
            pos1++;
        }
        
        if(pos1>pos2 && tipa_b[0]==-1)
            pos2=(pos1)%n;
        for(int j=0;j<in_b[c1[i].s];j++)
        {
            while(tipa_b[pos2]!=-1)
                pos2=(pos2+1)%n;
            tipa_b[pos2]=c1[i].s;
            pos2=(pos2+1)%n;
        }
    }
    
    for(int i=0;i<tipa_b.size();i++)
        if(tipa_b[i]!=-1)
            in_b[tipa_b[i]]--;
    
    vector<int> left;
    for(pii p : in_b)
        for(int i=0;i<p.s;i++)
            left.pb(p.f);
    for(int i=0;i<tipa_b.size();i++)
        if(tipa_b[i]==-1)
        {
            tipa_b[i]=left.back();
            left.pop_back();
        }
        
//    write(tipa_a);
//    write(tipa_b);
    
    int ok=1;
    for(int i=0;i<n;i++)
        if(tipa_a[i]==tipa_b[i])
            ok=0;
    if(!ok)
    {
        cout<<"No\n";
        return 0;
    }
    
    vector<int> res(n,-1);
    
    for(int i=0;i<n;i++)
    {
        res[pos[tipa_a[i]].back()]=tipa_b[i];
        pos[tipa_a[i]].pop_back();
    }
    
    cout<<"Yes\n";
    write(res);
    
        
}
