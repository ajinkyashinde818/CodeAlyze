#include<stdio.h>
int main(){
	int n,m,i,a[100],temp,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(j=0;j<m;j++){
		for(i=0;i<n-1;i++){
			if((a[i]%(j+1))>(a[i+1]%(j+1))){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
