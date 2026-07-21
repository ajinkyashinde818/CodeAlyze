#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s[100001],d=0,f[100001],g,h,i,j;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&s[i]);
		f[i]=0;
	}
	g=1;
	f[0]++;
	i=s[0];
	while(1){
		if(i==2) break;
	//	printf("%d\n",i);
		f[i-1]++;
	//	for(j=0;j<a;j++) printf("%d   %d\n",j,f[j]);
		if(f[i-1]==2){
			d=-1;
			break;
		}
		if(i==2) break;
		g++;
		i=s[i-1];
	}
	if(d==-1) printf("-1\n");
	else printf("%d\n",g);
	return 0;
}
