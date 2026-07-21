#include<stdio.h>
int main(){
int nlist[10000];
int i=0;
while(1){
scanf("%d",&nlist[i]);

if(nlist[i]==0)
break;
i++;
}
for(int j=0;j<i;j++){
printf("Case %d: %d\n",(j+1),nlist[j]);
}
return 0;
}
