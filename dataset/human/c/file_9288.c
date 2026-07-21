#include <stdio.h>
int main(){
int n,height,i,c;
int count=0;
scanf("%d%d",&n,&height);
for (i=1; i<=n; i++){
    scanf("%d",&c);
    if (c>=height){
        count++;
    }
}
printf("%d",count);
return 0;
}
