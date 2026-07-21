#include <stdio.h>

int main(){
    int k, s, valores = 0;
    scanf("%d %d", &k, &s);
    for (int x = 0; x <= k; x++){
        for (int y = 0; y <= k; ++y){
            int z = s - x - y;
            if (0 <= z && z <= k)
                valores += 1;
        }
    }
    printf("%d\n", valores);
    return 0;
}
