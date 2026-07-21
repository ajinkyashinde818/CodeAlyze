#include<stdio.h>
#define N 200000
int main(void){
	int set;
	int i;
	int a[N];
	int max, min;
	int tmp;
	scanf("%d", &set);
	for(i=0;i<set;i++) {
		scanf("%d",&a[i]);
	}

	for(i=1;i<set;i++){
		if(i==1){
			max = a[1]-a[0];
			min = a[0];
		}
		tmp = a[i]-min;
		if(tmp>max)max = tmp;
		if(a[i]<min)min=a[i];
	}
	printf("%d\n", max);
	return 0;
}
