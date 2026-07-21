#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
long long out;
int a,b;
scanf("%d %d",&a,&b);
for(out=1;;out++){
    if((a*out)%b==0){printf("%lld",a*out);break;}
}
return 0;
}
