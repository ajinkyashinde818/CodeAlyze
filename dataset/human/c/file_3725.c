#include<stdio.h>

int main(){
    int a,b;
    long int base;
    int tmp;
    if(scanf("%d%d",&a,&b)!=2) return -1;
    base = ((long int)a*(long int)b);
    //printf("%d\n",a*b);
    //printf("%d\n",100000*99999);
    while(a%b!=0){
        tmp = a;
        a = b;
        b = tmp%b;
    }
    //printf("%ld,%d\n",base,b);
    printf("%ld\n",base/(long int)b);
    return 0;
}
