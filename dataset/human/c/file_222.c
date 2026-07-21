#include <stdio.h>

int main(){
    long long int a;
    scanf("%lld", &a);
    long long int all[a];
    int i;
    int fo = 0;
    int min_index=0;
    int firstflag = 1;
    for(i=0; i<a; i++){
        scanf("%lld", &all[i]);
        if(all[i] < 0){
            fo++;
        }
        if(firstflag == 1){
            min_index = i;
            firstflag = 0;
        }
        if(all[i]*all[i] < all[min_index]*all[min_index]){
            min_index = i;
        }
    }
    fo = fo%2;
    if(fo == 0){
        long long int sum = 0;
        int j;
        for(j=0; j<a; j++){
            if(all[j]<0){
                sum+=-all[j];
            }
            else{
                sum+=all[j];
            }
        }
        printf("%lld", sum);
    }
    else{
        long long int sum = 0;
        int j;
        for(j=0; j<a; j++){
            if(j == min_index){
                if(all[j] < 0){
                    sum+=all[j];
                }
                else{
                    sum-=all[j];
                }
            }
            else if(all[j]<0){
                sum+=-all[j];
            }
            else{
                sum+=all[j];
            }
        }
        printf("%lld", sum);
    }
}
