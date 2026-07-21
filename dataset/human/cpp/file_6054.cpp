#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long int c, x[100001], v[100001];
	long long int vsum[100001], vsum1[100001];
	vsum[0]=0;
	vsum1[0]=0;
	scanf("%d %lld", &n, &c);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld", &x[i], &v[i]);
		if(i==1){
			vsum[1]=v[1];
		}else{
			vsum[i]=vsum[i-1]+v[i];
		}
	}
	for(int i=1; i<=n; i++){
		if(i==1){
			vsum1[1]=v[n];
		}else{
			vsum1[i]=vsum1[i-1]+v[n+1-i];
		}
	}
	long long int vmax1[100001]={}, vmax2[100001]={}, vmaxinv1[100001]={}, vmaxinv2[100001]={};
	for(int i=1; i<=n; i++){
		if(vmax1[i-1]<vsum[i]-x[i]){
          vmax1[i]=vsum[i]-x[i];
        }else{
          vmax1[i]=vmax1[i-1];
        }
      
	}
	for(int i=1; i<=n; i++){
		if(vmax2[i-1]<vsum[i]-2*x[i]){
          vmax2[i]=vsum[i]-2*x[i];
        }else{
          vmax2[i]=vmax2[i-1];
        }
	}
	for(int i=1; i<=n; i++){
		if(vmaxinv1[i-1]<vsum1[i]-(c-x[n+1-i])){
          vmaxinv1[i]=vsum1[i]-(c-x[n+1-i]);
        }else{
          vmaxinv1[i]=vmaxinv1[i-1];
        }
	}
	for(int i=1; i<=n; i++){
		if(vmaxinv2[i-1]<vsum1[i]-2*(c-x[n+1-i])){
          vmaxinv2[i]=vsum1[i]-2*(c-x[n+1-i]);
        }else{
          vmaxinv2[i]=vmaxinv2[i-1];
        }
	}
	long long int ans=0;
	for(int i=0; i<=n; i++){
		if(ans<vmax1[i]+vmaxinv2[n-i]) ans=vmax1[i]+vmaxinv2[n-i];
		if(ans<vmax2[i]+vmaxinv1[n-i]) ans=vmax2[i]+vmaxinv1[n-i];
	}
 
	printf("%lld\n", ans );
	return 0;
}
