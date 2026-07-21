#include<stdio.h>

int main(void){

int a, b, k, i;
int count = 0;
int ans = 0;

scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &k);

if(a >= b){
    for(i = b; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            count += 1;
            if(count == k){
                ans = i;
            }
        }
    }
}

else{
    for(i = a; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            count += 1;
            if(count == k){
                ans = i;
            }
        }
    }
}


printf("%d\n", ans);

return 0;
}
