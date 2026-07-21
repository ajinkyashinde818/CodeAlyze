#include<stdio.h>
#include<string.h>
#include<math.h>
int a,s,d[200000],f[200000],g[200000],h,x[200000],c[200000],q=0;
int main(void)
{
	int i,j,k;
	scanf("%d %d",&a,&s);
	for(i=0;i<=a;i++){
		g[i]=0;
		x[i]=0;
		c[i]=0;
	}
	i=0;
	j=0;
	while(1){
		if(i==s) break;
		i++;
		scanf("%d %d",&d[j],&f[j]);
		if(d[j]!=1&&f[j]!=a) j--;
		g[d[j]]=1;
		x[f[j]]=1;
		j++;
	}
	/*for(i=0;i<j;i++){
		if(x[d[i]]==0&&g[f[i]]==0){
			d[i]=-1;
			f[i]=-1;
		}
	}*/
	for(i=0;i<j;i++){
			if(d[i]==1)	c[f[i]]++;
			if(f[i]==a) c[d[i]]++;
	}
	//for(i=0;i<=a;i++)	printf("%d\n",c[i]);
	h=0;
	for(i=1;i<=a;i++){
		if(c[i]>=2){
			h=1;
			break;
		}
	}
	if(h==0) printf("IMPOSSIBLE\n");
	else printf("POSSIBLE\n");
	return 0;
}
