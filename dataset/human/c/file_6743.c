#include<stdio.h>

int main(){
	int n,m;
	int i;
	int s[10001][2]={0};
	while(scanf("%d%d",&n,&m),n!=0&&m!=0){
		int a[501]={0},b[501]={0},cnt=0;
		for(i=1;i<=m;i++){
			scanf("%d%d",&s[i][0],&s[i][1]);
			if(s[i][0]==1)a[s[i][1]]=1,b[s[i][1]]=1;
		}
		for(i=1;i<=m;i++){
			if(a[s[i][0]]==1)b[s[i][1]]=1;
			if(a[s[i][1]]==1)b[s[i][0]]=1;
		}
		for(i=2;i<=n;i++)if(b[i]==1)++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
