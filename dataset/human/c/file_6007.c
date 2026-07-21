//
// Created by syakushimo nekomo on 2018/02/28.
//
#include <stdio.h>
int main(void) {
    int n=0;
    scanf("%d",&n);
    int max;
    int min;
    int difference;
    int tmp;
    scanf("%d",&tmp);
    scanf("%d",&min);
    difference=min-tmp;
    max=min;
    if(tmp<min)
    {
        min=tmp;
    }
    for(int i=2;i<n;i++)
    {
        //最大値が更新される度に最小値と比較する
        scanf("%d",&tmp);
        if(tmp>=max){
            max = tmp;
            if(max-min>difference)
            {
                difference = max - min;
            }
        }else if(tmp<=min)
        {
            min=tmp;
            //それ以前の最高値は無意味なのでminに合わせる
            max=min;
        }
    }
    printf("%d\n",difference);
}
