#include<stdio.h>
int main(void)
{
	int w,h,n,i,x[10000+1],y[10000+1],a,b,cnt;
	scanf("%d %d %d",&w,&h,&n);
	for(i=1;i<=n;i++) {
		scanf("%d %d",&x[i],&y[i]);
	}
	a=x[1];
	b=y[1];
	cnt=0;
	for(i=1;i<=n;i++) {
		while(1){
			if(a==x[i] && b==y[i]) {
				break;
			}
			if(a<x[i] && b<y[i]) {
				a++;
				b++;
				cnt++;
			}
			else if(a>x[i] && b>y[i]) {
				a--;
				b--;
				cnt++;
			}
			else if(a==x[i] && b<y[i]) {
				b++;
				cnt++;
			}
			else if(a==x[i] && b>y[i]) {
				b--;
				cnt++;
			}
			else if(a<x[i] && b==y[i]) {
				a++;
				cnt++;
			}
			else if(a>x[i] && b==y[i]) {
				a--;
				cnt++;
			}
			else if(a<x[i] && b>y[i]) {
				a++;
				cnt++;
			}
			else if(a>x[i] && b<y[i]) {
				a--;
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
