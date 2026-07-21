#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*

*/



int main(void){
	ll n,sum=0,a[1010][1010],cur=1;
	cin>>n;
	reg(i,1,100010){
		rep(j,i){
			a[j][i-1]=cur;
			a[i][j]=cur;
			cur++;
		}
		sum+=2*i;
		if(sum>n*2)break;
		if(sum==n*2){
			//可能
			cout<<"Yes"<<endl;
			cout<<i+1<<endl;
			rep(j,i+1){
				printf("%d ",i);
				rep(k,i){
					printf("%lld ",a[j][k]);
				}
				printf("\n");
			}
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
