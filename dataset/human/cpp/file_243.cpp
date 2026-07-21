#include <bits/stdc++.h>
using namespace std;

struct P
{
    int x,y;
    bool operator<(const P &a)const{
        if(y!=a.y) return y>a.y;
        return x>a.x;
    }
};

vector<P> v;
//bitset<4001000> b;
int i,n,d,m,k,a,b,c;
int e;
int o[1];
int l[1];
int j[1];

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
int px[10]={-1,1,1,-1,1,1,-1,-1},py[10]={1,1,-1,-1,1,-1,1,-1};
long long mod=1000000007,mod2=1000000009,mod3=2017;
long long x,z,y;
double pi=3.14159265;
P u[1];
stack<int> s;
//set<int> se[33],s1;

//priority_queue<P> q;
queue<int> q;
string r;

char r1[1],r2[1];
//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
//v.resize(unique(v.begin(),v.end())-v.begin());

bool as(P a,P b)
{
    if(a.x!=b.x)
    //return a.y>b.y;
    return a.x<b.x;
    return a.y<b.y;
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//rng();



int main()
{
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(int t=0;t<=d;t++)
        for(int w=0;w<=d;w++)
        if(d>=t*a+w*b&&(d-t*a-w*b)%c==0) k++;
    printf("%d",k);
}
