#include <stdio.h>

void reset(int w[1024][1024],int l[]){
	int i,j;
	for(i = 0;i < 1024;i++){l[i] = 0;}
	for(i = 0;i < 1024;i++){
		for(j = 0;j < 1024;j++){w[i][j] = 0;}
	}
}

int main(void) {
	int n,m,w[1024][1024],l[1024],i,j,a,b,res;
	while(scanf("%d",&n) , n != 0){
		scanf("%d",&m);
		res = 0;
		reset(w,l);
		for(i = 1;i <= m;i++){
			scanf("%d%d",&a,&b);
			w[a][b]++;
			w[b][a]++;
		}
		for(i = 1;i <= n;i++){
			if(w[1][i] == 0){continue;}
			l[i] = 1;
			for(j = 1;j <= n;j++){
				if(w[i][j] != 0){l[j] = 1;}
			}
		}
		for(i = 2;i <= n;i++){if(l[i]){res++;}}
		printf("%d\n",res);
	}
	return 0;
}
