#include<stdio.h>
int main(){
int a,b;
scanf("%d %d",&a,&b);
if(a==0){
if(b>=1868 && b<=1911){
printf("M%d\n",b-1867);
}
else if(b<=1925){
printf("T%d\n",b-1911);
}
else if(b<=1988){
printf("S%d\n",b-1925);
}
else if(b<=2016){
printf("H%d\n",b-1988);
}
}
else if(a==1){
printf("%d\n",b+1867);
}
else if(a==2){
printf("%d\n",b+1911);
}
else if(a==3){
printf("%d\n",b+1925);
}
else if(a==4){
printf("%d\n",b+1988);
}
return 0;
}
