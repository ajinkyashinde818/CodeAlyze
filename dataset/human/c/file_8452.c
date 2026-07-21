#include<stdio.h>
int main(){
	int n,k,i,j,a[101],x;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=1;i<=k;i++){
		for(j=0;j<n-1;j++){
			if(a[j]%i>a[j+1]%i){
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	for(i=0;i<n;i++)printf("%d\n",a[i]);
	return 0;
}
