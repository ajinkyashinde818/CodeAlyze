#include<stdio.h>
main()
{
int H,W,h,w;
while(scanf("%d %d",&H,&W)!=EOF){
if(H==0 && W==0) return 0;
for(h=0;h<H;h++){
for(w=0;w<W;w++){
if(h%2==0){
if(w%2==0){printf("#");}
if(w%2==1){printf(".");}
}
if(h%2==1){
if(w%2==0){printf(".");}
if(w%2==1){printf("#");}
}
}
printf("\n");
}
printf("\n");
}
return 0;
}
