#include<stdio.h>
int main(){
	int n,m,k,i,j,a[101],te;
	scanf("%d",&n);
	scanf("%d",&m);
	for(j=1;j<=n;j++){
		scanf("%d",&a[j]);
	}
	i=1;
	for(j=1;j<=m;){
		if(i<n&&1<=i){
			if(a[i]%j>a[i+1]%j){
			te=a[i];
			a[i]=a[i+1];
			a[i+1]=te;
			i++;
			}
			else{
				i++;
			}
		}
		if(i==n){
			j++;
			i=1;
		}
	}
	for(j=1;j<=n;j++){
		printf("%d\n",a[j]);
	}
	return 0;
}
