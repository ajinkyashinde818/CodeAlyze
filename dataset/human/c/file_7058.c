#include<stdio.h>

int main(void){
int h, w, i, k;
while(1){
scanf("%d %d", &h, &w);
if(h == 0 && w == 0){
break;
}
for(i = 0; i < h; i++){
for(k = 0; k < w; k++){
	(i%2 == 0?((k%2) == 0?printf("#"):printf(".")):((k%2) == 0?printf("."):printf("#")));
}
printf("\n");
}
printf("\n");
}
return 0;
}
