//B - Roller Coaster
#include <stdio.h>

int main(void){
    int n, k, i, rideRCoaster=0;
    scanf("%d %d", &n, &k);
    int h[100000]={0};
    for(i=0; i<n; i++) scanf("%d", &h[i]);

    for(i=0; i<n; i++){
        if(h[i]>=k) rideRCoaster++;
    }
    printf("%d\n", rideRCoaster);
    return 0;
}
