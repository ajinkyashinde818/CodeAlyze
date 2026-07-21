#include <stdio.h>
int main (void){
    int max;
    int sum;
    scanf("%d %d",&max,&sum);
    //経験上、3値のうち、2値は同じだ
    //1値固定で2値を決定させるながれ
    int count=0;
    int loop1,loop2,loop3,temp;
    if(max*3==sum){//例外、これは1パターンのみ
        printf("1\n");
        return 0;
    }
    for(loop1=0;loop1<=max;loop1++){//x=loop1なら？
        for(loop2=0;loop2<=max;loop2++){
            if(sum-(loop1+loop2)<=max && sum-(loop1+loop2)>=0){
                count++;
                //printf("%d %d %d\n",loop1,loop2,(sum-(loop1+loop2)));
            }
        }
    }
    printf("%d\n",count);
    return 0;
    
}
