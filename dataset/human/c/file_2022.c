#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define INFTY 999999


int main(void){
    unsigned long a,b,c;
    scanf("%lu %lu %lu", &a, &b, &c);

    unsigned long ans;

    //もし毒入りクッキーより解毒剤クッキーの方が多ければ、
    //毒入り美味しいクッキーを全て食べられる+解毒剤美味しいクッキーも食べられる
    if(c<=a+b){
        ans=b+c;
    }
    //毒入りクッキーより解毒剤クッキーの方が少なければ
    else{
        unsigned long poison=a+b;
        ans=poison+b+1;
    }

    printf("%lu\n",ans);
    
    return 0;
    
}
