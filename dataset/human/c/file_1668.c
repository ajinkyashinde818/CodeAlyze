#include<stdio.h>


int main(void){

	int n;
	int a[20];
	int b[20];
	int c[20];
	int i;
	int ret;
	int past;


	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}

	for(i=0;i<n-1;i++){
		scanf("%d",&c[i]);
	}

	ret = b[a[0]-1];
	past = 0;
	for(i=1;i<n;i++){
		ret += b[a[i]-1];
		if(a[i-1] == a[i] -1){
			ret += c[a[i]-2];
		}
	}

	printf("%d\n",ret);

	return 0;
}
