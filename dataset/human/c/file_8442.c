//0620
#include<stdio.h>
int main(void){
	int a[101],n,m,i,b,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		b=1;
		while(b!=n){
			if(a[b]%i>a[b+1]%i){
				t=a[b];
				a[b]=a[b+1];
				a[b+1]=t;
			}
			b++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
