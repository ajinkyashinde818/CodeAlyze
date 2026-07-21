#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

#define MOD ((lli)(1000000007))

char s[200005];
int main(void){
	int n;
	scanf("%d%s",&n,s);
	lli ans=1;
	int en=0;
	rep(i,n*2){
		if((en%2==0) == (s[i]=='W')){
			if(en<=0){
				puts("0");
				return 0;
			}
			else{
				ans=(ans*en)%MOD;
				en--;
			}
		}
		else en++;
		//printf("%d %d\n",i,en);
	}
	if(en>0){
		puts("0");
		return 0;
	}
	//printf("%lld %d\n",ans);
	reg(i,1,n){
		ans = (ans*i)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
