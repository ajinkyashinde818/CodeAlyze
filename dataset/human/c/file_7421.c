#include<stdio.h>

int main(void){
int i,k,a[10000];

for(i=0;i<10000;i++){
scanf("%d",&a[i]);
 if(a[i]==0) break;
}

for(k=0;k<=i-1;k++){
printf("Case %d: %d\n",k+1,a[k]);
}

return 0;
}
