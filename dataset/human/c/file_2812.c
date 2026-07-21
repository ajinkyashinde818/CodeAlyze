#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int k, s;
    int x, y, z, cnt = 0;
    
    scanf("%d%d", &k, &s);
    for(x = 0; x <= k; x++){
        for(y = x; y <= k; y++){
            for(z = y; z <= k; z++){
                if(x+y+z == s){
                    if(x == y && y == z){
                        cnt++;
                    }else if(x == y || y == z || z == x){
                        cnt += 3;
                    }else{
                        cnt += 6;
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
