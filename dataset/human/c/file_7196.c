#include<stdio.h>

int main(){

int i,j, h, w, f;

while(1){
scanf("%d %d", &h, &w);

for ( i = 0; i < h; i++ ){
	f=1-(i%2);
    for ( j = 0; j < w; j++ ){
		f ? printf("#") : printf(".");
		f =!f;
    }
    printf("\n");
}
if (h==0) return 0;
    printf("\n");
}
}
