#include <stdio.h>
int main (void){
int a[10000],i=0,n=0,j;
a[0]=32;
while(a[i]!=0){
	i++;
	n++;
	scanf("%d",&a[i]);
}
for(j=1;j<n;j++){
	printf("Case %d: %d\n", j,a[j]);
}



return 0;
}
