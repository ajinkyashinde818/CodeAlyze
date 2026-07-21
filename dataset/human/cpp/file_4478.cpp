#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	int a = (n+2)/2;
	if(n>a)
	{
		for(int i=0;i<a;i++)printf("0 ");
		for(int i=0;i<n-a-1;i++)printf("%d ",m);
		printf("%d\n",m);
	}
	else
	{
		if(n==1)printf("0\n");
		if(n==2)printf("0 0\n");
	}
	return 0;
}
