#include<stdio.h>
#include<stdlib.h>

int main(){
    long long int c;
    scanf("%lld",&c);
    long long int syou=c/11;
    int amari=c%11;
    int nokori=0;
    if(amari>=7) nokori=2;
    else if(amari==0) nokori=0;
    else nokori=1;
    printf("%lld\n",syou*2+nokori);

}
