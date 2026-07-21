#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int Rt[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", Rt + i);
    }

    int maxValue = Rt[1] - Rt[0];
    int min = Rt[0];

    for(int i = 0; i < n; i++) {
        if(Rt[i] < min) {
            min = Rt[i];
        } else {
            if((Rt[i] - min) > maxValue && i != 0) {
                maxValue = Rt[i] - min;
            }
        }
        
    }


    printf("%d\n", maxValue);

    return 0;
}
