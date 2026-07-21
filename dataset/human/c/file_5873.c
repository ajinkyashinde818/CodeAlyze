#include <stdio.h>

int main(void){
    int maxBenefit=-2000000000,min,size,i,price;
    scanf("%d",&size);
    scanf("%d",&min);

    for(i=1;i<=size-1;i++){
        scanf("%d",&price);
        maxBenefit=maxBenefit>(price-min)?maxBenefit:(price-min);//更新最大利益：比较当前值与此前最小值的差和此前的最大利益
        min=min<price?min:price;//更新最小值
    }

    printf("%d\n",maxBenefit);
    return 0;
}
