#include<stdio.h>
#include<string.h>
int main(){
    unsigned long long int a,b;
    scanf("%llu %llu",&a,&b);
    unsigned long long int ab = a * b;
    unsigned long long int hoge;
    if(a < b){
        hoge = a;
        a = b;
        b = hoge;
    }
    unsigned long long int fuga = a % b;
    while(fuga != 0){
        a = b;
        b = fuga;
        fuga = a % b;
    }
    printf("%llu",ab / b);
    return 0;
}
