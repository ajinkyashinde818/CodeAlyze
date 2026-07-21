#include<stdio.h>
#include<string.h>
#include<math.h>
int a,s,d,f[10001],g[10001],h,j,i,k,z[3],x;
int main(void)
{
	scanf("%d %d %d",&a,&s,&d);
	for(i=0;i<d;i++)
		scanf("%d %d",&f[i],&g[i]);
	for(i=0;i<d-1;i++){
		z[0]=0;
		z[1]=0;
		h=f[i+1]-f[i];
		k=g[i+1]-g[i];
		if(h<0){
			h*=-1;
			z[0]=1;
		}
		if(k<0){
			k*=-1;
			z[1]=1;
		}
		if(z[0]==z[1]){
			if(h>k)
				x+=h;
			else x+=k;
		}
		else
			x+=h+k;
	}
	printf("%d\n",x);
	return 0;
}
