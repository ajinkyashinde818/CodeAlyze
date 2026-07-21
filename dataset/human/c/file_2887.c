#include<stdio.h>

int main(){
    int k, s;
    scanf("%d%d", &k, &s);
    int x, y, z, count = 0;
    for(x = 0; x <= k; x++){
        for(y = 0; y <= k; y++){
            z = s-x-y;
            if(k >= z && z >= 0){
                count++;
            }
        }
    }
    printf("%d\n", count);
}
