#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 
int main(void) {
    // your code goes here
    int a,b,z;
    scanf("%d %d",&a,&b);
    if(a>=10){
        printf("%d",b);
    }else{
        z=100*(10-a);
        z=z+b;
        printf("%d",z);
    }
    return 0;
}
