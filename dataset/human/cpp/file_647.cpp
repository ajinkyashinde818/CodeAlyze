#include<bits/stdc++.h>
using namespace std;

int R,G,B,N;
long long ans=0;

int main(){
	scanf("%d%d%d%d",&R,&G,&B,&N);
	for(int i=0;i<=N;i++){
		int sum1=i*R;
		int n=N;
		n-=sum1;
		if(n<0) break;
		for(int j=0;j<=N;j++){
			int sum2=j*G;
			int m=n;
			m-=sum2;
			if(m<0) break;
			if(m%B==0) ans++; 
		}
	}
	printf("%lld",ans);
	return 0;
}
