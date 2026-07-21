#include <stdio.h>
/*
p==1 毒
p==0 健康
a 解毒剤入まずいクッキーの枚数
b 解毒剤入美味しいクッキーの枚数
c 毒入り美味しいクッキーの枚数
*/
int main(void){
    int a, b, c, cnt=0, p=0;

    scanf("%d %d %d", &a, &b, &c);

    while(1){
        if(p==0 && c>0){
            c=c-1;
            cnt++;
            p=1;
        }
        else if(c<=0)
            break;
        else  if(p==1 && b>0){
            b=b-1;
            cnt++;
            p=0;
        }
        else if(p==1 && a>0){
            a=a-1;
            p=0;
        }
        else
            break;
    }
    
    cnt=cnt+b;

    printf("%d\n", cnt);
    
    return 0;
}
