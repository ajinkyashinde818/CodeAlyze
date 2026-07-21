#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s[100],d,f,g,h,j,i;
	scanf("%d",&a);
	for(i=0;i<a;i++) scanf("%d",&s[i]);
	for(i=a;i>0;i--){
		d=0;
		for(j=0;j<a;j++) if(s[j]>=i) d++;
		if(d>=i) break;
	}
	printf("%d\n",i);
	return 0;
}
