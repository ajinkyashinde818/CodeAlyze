#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define mprint(x) printf(FORMATCONVERSION(x),(x))
#define FORMATCONVERSION(x) _Generic((x),\
                                    int:"%d",unsigned int:"%u",\
                                    double:"%lf",long long int:"%lld",\
                                    unsigned long long int:"%llu",\
                                    char :"%c",char*:"%s")
 
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n == m){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
