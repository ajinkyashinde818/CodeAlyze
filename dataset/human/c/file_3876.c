#include <stdio.h>
int main(void){
    // Your code here!
    int a,b,k;
    int i=0,i2=0;
    int ary[100];
    scanf("%d %d %d",&a,&b,&k);
    
    while(i<a || i<b){
        i++;
        if(a%i==0 && b%i==0){
            ary[i2]=i;
            i2++;
        }
    }
    printf("%d",ary[i2-k]);
    return 0;
}
