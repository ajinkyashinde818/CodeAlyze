#include <stdio.h>
  
int main(int argc, char *argv[]) {
    int k, s; 
    int cnt = 0;
    
    scanf("%d%d", &k, &s);
        
    for (int y = 0; y <= k; y++) {
        for (int x = 0; x <= k; x++) {
            int z = s - x - y;
            if (z >= 0 && z <= k ) cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
