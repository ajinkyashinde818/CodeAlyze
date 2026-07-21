/*
 * FileName:     C
 * CreatedDate:  2020-05-30 13:32:31 +0900
 * LastModified: 2020-05-30 13:44:02 +0900
 */

#include <stdio.h>
int gcd(int a, int b){
    int r;
    while(a%b!=0){
        r = a%b;
        a = b;
        b = r;
//        printf("(a,b,r)=(%d,%d,%d)\n",a,b,r);
    }
    return b;
}
int main(void){
    int a,b;scanf("%d %d",&a,&b);
    int g = gcd(a,b);
//    printf("%d\n",g);
    printf("%ld\n",(long int)a*(long int)b/(long int)g);
    return 0;
}
