#include <stdio.h>

int main(){
int h,w,i,j;

while(1){
scanf("%d %d",&h,&w);
if(h==0 && w==0)break;
for(i=0;i<h;i++){
for(j=0;j<w;j++){
if((j+i)%2==0){
printf("#");
}
else if((j+i)%2==1){
printf(".");
}
}
printf("\n");
}
printf("\n");

}

return 0;
}
