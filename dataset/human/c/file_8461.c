#include<stdio.h>
int main(){
int a[101],b,c,i,j,d;
scanf("%d %d\n",&b,&c);
for(i=0;i<b;i++){
scanf("%d\n",&a[i]);
}
for(i=1;i<c+1;i++){
for(j=0;j<b-1;j++){
if(a[j]%i>a[j+1]%i){
d=a[j];
a[j]=a[j+1];
a[j+1]=d;
}
}
}
for(i=0;i<b;i++){
printf("%d\n",a[i]);
}
return 0;
}
