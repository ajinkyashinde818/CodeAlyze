#include <stdio.h>

long ll(long a){
if(a<0) a=0-a;
return a;
}

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	long sum=0;
	for(i=0;i<n;i++) {scanf("%d",&a[i]);sum+=a[i];}
	long minxy;
	long sumx=0;
	short flag=0;
	for(i=0;i<n-1;i++){
		sumx+=a[i];
		if(flag==1){
			if(ll(sum-sumx*2)<minxy) minxy=ll(sum-sumx*2);
		}else{minxy=ll(sum-sumx*2);}
		flag=1;
	}
	printf("%d", minxy);
	return 0;
}
