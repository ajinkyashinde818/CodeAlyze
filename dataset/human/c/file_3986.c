#include<stdio.h>
 
int main(void)
{
   int a,b,c,d[100],e,i,z=1;

    scanf("%d%d%d",&a,&b,&c);
    
    for(i=0;i<a && i<b;i++){
        if(a%z == 0 && b%z == 0){
            d[e] = z;
            e++;
        }
        z++;
    }
    printf("%d\n",d[e-c]);
    
    return 0;
}
