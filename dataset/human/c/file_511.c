#include <stdio.h>
int main(void){
     long long int n,a[200000]={0},sum = 0,sunuke = 0,araiguma = 0,min = 10000000000;
    scanf("%lld", &n);
    for(int i = 0; i< n; i++){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    for(int j = 0; j < n-1; j++){
        sunuke +=a[j];
        araiguma = sum - sunuke;

        if(min > sunuke-araiguma && sunuke-araiguma >0){
            min = sunuke - araiguma;
        }else if(min > araiguma-sunuke && araiguma-sunuke >0){
            min = araiguma - sunuke;
        }else if(sunuke == araiguma){
            min = 0;
            break;
        }
    }
    if(min == 10000000000){
        min = 0;
    }
    printf("%lld", min);
    return 0;
}
