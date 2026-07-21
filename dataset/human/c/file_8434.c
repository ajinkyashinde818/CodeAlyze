#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s,d[1001],f,g,h,j,i,k;
	scanf("%d %d",&a,&f);
	for(i=0;i<a;i++)
		scanf("%d",&d[i]);
	for(s=1;s<=f;s++){
		for(i=0;i<a-1;i++){
			if(d[i+1]%s<d[i]%s){
				g=d[i];
				d[i]=d[i+1];
				d[i+1]=g;
			}
		}
	}
	for(i=0;i<a;i++)
		printf("%d\n",d[i]);
	return 0;
}
