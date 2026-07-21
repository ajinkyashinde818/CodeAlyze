//Robs Code
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
/***********MACROS***************/
#define int long long int
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define pii pair<int,int>
using namespace std;
int n,m,i,j,l,k,x,y,a,b,cnt[3],sum[3];
/***********MAIN**************/
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int r,b,g,n;
	cin>>r>>g>>b>>n;
	int cnt = 0;
	for(int x=0;x<=3000;x++){
		for(int y=0;y<=3000;y++){
			if((n - r*x - g*y)>=0 && (n - r*x - g*y)%b == 0){
				cnt++;
			}
		}
	}
	cout<<cnt;
    return 0;
}
//.........
