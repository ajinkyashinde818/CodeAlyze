#include <stdio.h>
int main(){
	int x[100000],a,i=0,j;

	while(1){
		scanf("%d",&a);
			if(a==0)
				break;
		x[i]=a;
		i++;
	}
	for(j=0;j<i;j++){
		printf("Case %d: %d\n",j+1,x[j]);
	}
	return 0;
}
