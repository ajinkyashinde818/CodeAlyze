#include<stdio.h>

int main(void){
    int k, s, count = 0;;
    scanf("%d %d", &k, &s);
    int t = s / 3, u, z; 

    for(int x = 0; x <= t; x++){
        u = s - x;
        for(int y = x; 2 * y <= u; y++){
            z = u - y;
            if(z <= k){
                if(x != y && y != z){
                    count += 6;
                }else if(x == y && z == y){
                    count++;
                }else{
                    count += 3;
                }
            }
        }
    }
    printf("%d", count);

    return 0;
}
