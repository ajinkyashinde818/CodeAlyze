#include <stdio.h>

int main(void){

int i=0, j, x;
int data[10000];

do{
scanf("%d", &x);
data[i]=x;
i++;
}while(x);

for(j=0;j<i-1;j++){
printf("Case %d: %d\n", j+1, data[j]);
}

return 0;
}
