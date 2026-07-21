#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))

int main(){
	int k,s,a,i,j;
	long ans=0;
	scanf("%d %d",&k,&s);
	a=(s+2)/3;
	for(i=a;i<=min(k,s);i++){
		if(s==i*3){
			ans++;
			continue;
		}
		j=0;
		if(s>=2*i) j++;
		if((s-i)%2==0) j++;
		ans+=3*j+6*(min(i,s-i)-(s-i+1)/2-j+1);
	}
	printf("%ld\n",ans);
	return 0;
}
