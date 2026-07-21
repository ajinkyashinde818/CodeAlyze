#include <stdio.h>

int main(void)
{
        int n;
        scanf("%d", &n);
        int r[n];

        int i, j, max, r_min;
        for(i = 0; i < n; i++){
                scanf("%d", &r[i]);
        }

        max = r[1] - r[0];
        r_min = r[0];
        for(i = 0; i < n - 1; i++){
                if((i == 0) || (r[i] < r_min)){
                        for(j = i + 1; j < n; j++){
                                if(r[j] - r[i] > max){
                                        max = r[j] - r[i];
                                        r_min = r[i];
                                }
                        }
                }
        }
        printf("%d\n", max);

        return 0;
}
