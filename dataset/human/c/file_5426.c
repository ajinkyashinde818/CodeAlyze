#include<stdio.h>
int main(void)
{
	int a,b,c,d[10001],e[10001],i,cnt=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<c;i++){
		scanf("%d%d",&d[i],&e[i]);
	}
	for(i=1;i<c;i++){
		while(d[i-1]!=d[i]||e[i-1]!=e[i]){
			if(d[i-1]>d[i]&&e[i-1]>e[i]){
					d[i-1]--;	e[i-1]--;
					cnt++;
			}
			else if(d[i-1]>d[i]){
				d[i-1]--;
				cnt++;
			}
			else if(e[i-1]>e[i]){
				e[i-1]--;
				cnt++;
			}
			if(d[i-1]<d[i]&&e[i-1]<e[i]){
					d[i-1]++;
					e[i-1]++;
					cnt++;
			}
			else if(d[i-1]<d[i]){
				d[i-1]++;
				cnt++;
			}
			else if(e[i-1]<e[i]){
				e[i-1]++;
				cnt++;
			}
		}
	//	printf("%d %d %d\n",d[i-1],e[i-1],cnt);
	}
	printf("%d\n",cnt);
	return 0;
}
