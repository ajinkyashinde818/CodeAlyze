#include <stdio.h>

int main(void)
{

int i,n,x[10000];

i=0;

while(1){
 scanf("%d",&x[i]);
 if(x[i] == 0){
 break;
}

i++;

}

n=i;

for(i=0;i<n;i++){
 printf("Case %d: %d\n",i+1,x[i]);
}
 return 0;
}
