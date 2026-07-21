#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=l;i<r;i++)

ll b[20][5];

int main(){
	ll h;
	while(scanf("%lld",&h),h){
		rep(i,0,h)rep(j,0,5)scanf("%lld",&b[i][j]);
		ll ans=0,flag=1;
		while(flag){
			flag=0;
			//消滅
			rep(i,0,h)rep(j,0,3){
				if(b[i][j]!=-1&&b[i][j]==b[i][j+1]&&b[i][j+1]==b[i][j+2]){
					flag=1;
					ll temp=b[i][j];
					rep(k,j,5){
						if(b[i][k]!=temp)break;
						ans+=temp;
						b[i][k]=-1;
					}
				}
			}
			//落下
			rep(j,0,5){
				ll crr=h-1;
				for(int i=h-1;i>=0;i--)if(b[i][j]!=-1)b[crr--][j]=b[i][j];
				while(crr>=0)b[crr--][j]=-1;
			}
		}
		printf("%lld\n",ans);
	}
}
