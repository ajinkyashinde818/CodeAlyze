#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    int x,y,z;

    bool operator<(const P &a)const{
              return z>a.z;
    }

};

vector<int> v[3333];

//bitset<4001000> b;
int a,i,b,n,d,c,m,k;


int o[111113];
int l[111113];
int j[1];
int e;


int dx[10]={2,2,-2,-2,1,1,-1,-1},dy[10]={1,-1,1,-1,2,-2,2,-2};

//int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long mod=998244353,mod2=1000000009,mod3=2017;
long long x,z,y;
double pi=3.14159265;
//P u[222221];
stack<int> s;
//set<int> s[222][22];
//priority_queue<int> q;

//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
//list<int> l;

//string r1,r2;
//char r1[33],r2[33];
//deque<int> de;
//srand((int)time(NULL));
bool as(P a,P b)
{
    return a.x<b.x;
}
bool qw(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%d",&a);
    if(a==1)
    {
        printf("Yes\n2\n1 1\n1 1");
        return 0;
    }
    if(a==2)
    {
        puts("No");
        return 0;
    }
    for(int t=3;t*(t-1)/2<=a;t++)
    {
        if(t*(t-1)/2==a)
        {
            int i=1;
            for(int h=1;h<=t;h++)
            for(int p=h+1;p<=t;p++)
            {
                v[h].push_back(i);
                v[p].push_back(i);
                i++;
            }
            printf("Yes\n%d\n",t);
            for(int i=1;i<=t;i++)
            {
                printf("%d ",v[i].size());
                for(int h=0;h<v[i].size();h++)
                    printf("%d ",v[i][h]);
                puts("");
            }
            return 0;
        }
    }
    puts("No");
}
