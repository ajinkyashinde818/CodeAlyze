#include <stdio.h>
int main()
{
int i,j,count=0,k=0,l=0,x[100000];
scanf("%d", &i);
for(j=0;j<i;j++){
scanf("%d",&x[j]);
if(x[j] ==2) l++;
}
if(l==0){
printf("-1\n");
return 0;
}
while(x[k]!=2){
k=x[k]-1;
count++;
if(count>j)break;
}
count++;
if(count>j){
printf("-1\n");
return 0;
}
printf("%d\n",count);
return 0;
}
