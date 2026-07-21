#include <stdio.h>
 
int main(void)
{
int n,i,R[200000],max,min;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&R[i]);
}
min=R[0];
max=R[1]-R[0];
for(i=1;i<n;i++){
if(max<R[i]-min){
max=R[i]-min;
}
if(min>R[i]){
min=R[i];
}
}
printf("%d\n",max);
return 0;
}
