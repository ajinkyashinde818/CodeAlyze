#include<stdio.h>
int main(){
	int a[101],sco,cnt,n,k,i,j,h;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;;i++){
		cnt=0;
		for(j=0;j<n;j++){
			if(a[j]>=i)++cnt;
			if(cnt>=i){
				sco=i;
				break;
			}
			else if(j==n-1){
				goto end;
			}
		}
	}
	end:
	printf("%d\n",sco);
	return 0;
}
