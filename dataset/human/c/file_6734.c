#include <stdio.h>
volatile int a[10000];
volatile int b[10000];
volatile int m;

int friend2(int s){
	int i;
	for (i=0;i<m;i++){
		if (a[i]==s){
			if(b[i]==1){
				return 1;
			}
		}else if (b[i]==s){
			if (a[i]==1){
				return 1;
			}
		}
	}
	return 0;
}

int friend(int s){
	int i;
	for (i=0;i<m;i++){
		if (a[i]==s){
			if (b[i]==1){
				return 1;
			}else if(friend2(b[i])==1){
				return 1;
			}
		}else if(b[i]==s){
			if (a[i]==1){
				return 1;
			}else if(friend2(a[i])==1){
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	for (;;){
		int i;
		for (i=0;i<10000;i++){
			a[i]=0;
			b[i]=0;
		}
		int n;
		int x=0;
		scanf("%d",&n);
		scanf("%d",&m);
		
		for (i=0;i<m;i++){
			scanf("%d %d",&a[i],&b[i]);
		}
		
		if (n==0&&m==0){
			break;
		}
		
		for (i=2;i<=n;i++){
			if(friend(i)==1){
				x++;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}
