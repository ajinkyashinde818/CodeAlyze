#include<stdio.h>
int main(){
	int n;
	int a[200000],max,min;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i==1)max=a[1]-a[0];
		if(i>0){
			int tem=a[i]-min;
			if(tem>max)max=tem;
			if(min>a[i])min=a[i]; 
		}
		else {
			min=a[0];
		}
	}
	printf("%d\n",max);
	return 0;
}
