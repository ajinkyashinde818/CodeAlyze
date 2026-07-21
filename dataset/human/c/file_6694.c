#include<stdio.h>
int x[10000],y[10000],f[10000];
int main(){
	int n,m,i,cnt1=0,cnt2,j;
	while(1){
		int p[501]={0};
		p[1]=1;
		cnt1=0;
		scanf("%d %d",&n,&m);
		if(n==0&&m==0){
			break;
		}
		for(i=0;i<m;i++){
			scanf("%d %d",&x[i],&y[i]);
			if(x[i]==1&&p[y[i]]==0){
				p[y[i]]=1;
				f[cnt1]=y[i];
				cnt1++;
			}
			if(y[i]==1&&p[x[i]]==0){
				p[x[i]]=1;
				f[cnt1]=x[i];
				cnt1++;
			}
		}
		cnt2=cnt1;
		for(i=0;i<cnt2;i++){
			for(j=0;j<m;j++){
				if(f[i]==x[j]&&p[y[j]]==0){
					p[y[j]]=1;
					cnt1++;
				}
				if(f[i]==y[j]&&p[x[j]]==0){
					p[x[j]]=1;
					cnt1++;
				}
			}
		}
		printf("%d\n",cnt1);
	}
	return 0;
}
