#include <stdio.h>

int main(void) {
    int around = 0;
    int N = 0;
    scanf("%d %d", &around, &N);
    
    int house[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &house[i]);
    }

    int dist[N];
    int max_dist = 0;

    for (int i=0; i<N-1; i++) {
        dist[i] = house[i+1] - house[i];
        if (max_dist < dist[i]) {
            max_dist = dist[i];
        }
    }
    dist[N-1] = around - house[N-1] + house[0];
    if (max_dist < dist[N-1]) {
        max_dist = dist[N-1];
    }
    
    printf("%d\n", around - max_dist);

    return 0;
}
