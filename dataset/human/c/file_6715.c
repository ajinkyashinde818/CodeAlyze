#include<stdio.h>
int main(){
	int s,n,k,i,j,a[10001][2],m[501];
	while(scanf("%d%d",&n,&k),n!=0&&k!=0){
		for(i=0;i<n;i++)m[i]=0;
		for(i=0;i<k;i++){
			scanf("%d%d",&a[i][0],&a[i][1]);
			if(a[i][0]==1)m[a[i][1]-1]=1;
		}
		for(i=0;i<n;i++){
			if(m[i]==1){
				for(j=1;j<k;j++){
					if(m[a[j][0]-1]==1&&m[a[j][1]-1]==0)m[a[j][1]-1]=2;
					if(m[a[j][1]-1]==1&&m[a[j][0]-1]==0)m[a[j][0]-1]=2;
				}
			}
		}
		m[0]=0,s=0;
		for(i=0;i<n;i++)if(m[i]!=0)++s;
		printf("%d\n",s);
	}
	return 0;
}
