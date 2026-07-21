#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second;
#define F first;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()


//n==target m=coins
/**
number of ways of gathering coins:::::::::::
**/
ll Wayscoin(ll arr[],ll m,ll n ){
	 ll i, j, x, y;
    ll table[n + 1][m];
    for (j = 1; j < m; j++)
        table[0][j] = 1;
    table[0][0]=1;
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x=0,y=0;
            //including
            if(i-arr[j]>=0)
            	x=table[i-arr[j]][j];
            //excluding
            if(j>0)
            	y=table[i][j-1];
            table[i][j]=x+y;
        }
    }
    return table[n][m - 1];
}


/***
    Minimum Number of Coins and actual coins to print:
***/



vpshVar(){
    ll test,N;
     N=3;
     ll arr[3];
     for(ll i=0;i<N;i++){
        sl(arr[i]);
     }
     ll target;
     sl(target);
     //pl(coin(target,arr,N));
     //BottomUp(target,arr,N);
     cout<<Wayscoin(arr,N,target)<<endl;
return 0;
}
