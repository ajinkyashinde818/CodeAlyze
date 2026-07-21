#include<stdio.h>
int main(void){

int i, d = 1;
scanf("%d", &i);
printf("Case %d: %d\n", d, i);
while (i>0){
scanf("%d", &i);
if (i == 0){ break; }
else{
d = d + 1;
printf("Case %d: %d\n", d, i);
}
}

	return 0;
}
