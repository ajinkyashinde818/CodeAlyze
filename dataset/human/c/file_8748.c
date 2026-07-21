#include <stdio.h>

int count;

int push(int *a,int num,int n){
	if(a[num-1]==2){
		count++;
		return;
	}else if(count==n){
		count=-1;
		return;
	}else if(count<n||a[num-1]!=2){
		++count;
		push(a,a[num-1],n);
	}
}

int main(){
	int n;
	scanf("%d\n",&n);
	int a[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d\n",&a[i]);
	}
	push(a,1,n);
	printf("%d",count);
}
