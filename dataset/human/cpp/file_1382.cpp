#include <bits/stdc++.h>
using namespace std;
int R,G,B,N,ans=0;
int main(){
	scanf("%d %d %d %d",&R,&G,&B,&N);
	for(int i=0;i*R<=N;i++) for(int j=0;j*G+i*R<=N;j++) if((N-i*R-j*G)%B==0) ans++; 
	printf("%d\n",ans);
}
