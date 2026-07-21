#include <stdio.h>
#include <math.h>

const int Num = 200001; //defineよりいいらしい
int times; //how many times
    
long long int max_profit(int *price);

int main () {

    int price[Num];
    int i; 
    
    scanf ("%d",&times);
    
    for (i = 0;i < times;i ++) {
        scanf ("%d",&price[i]);
    }
    
    printf ("%lld\n",max_profit(price) );
    return 0;
}

long long int max_profit(int *price) {
    int i;
    long long int maxsa,min; //max初期化命 でも0やと事故る
    //max差　ただ最小値
    maxsa = -10000000000;
    
    /*ただただ差だけを考えないと事故る
      全走査しないと*/
    min = price[0];
    for (i = 1;i < times;i ++) {
        maxsa = (maxsa < price[i] - min) ? (price[i] - min) : maxsa;
        min = (min > price[i]) ? price[i] : min; 
    }
    return maxsa;
}
