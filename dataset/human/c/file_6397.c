#include <stdio.h>

int main(void)
{
    int i, score, minv, count;
    int data[200000];

    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        scanf("%d", &data[i]);
    }

    score = data[1] - data[0];
    minv = data[0];

    for (i = 1; i < count; i++) {
        if (score < data[i] - minv) {
            score = data[i] - minv;
        }

        if (minv > data[i]){
            minv = data[i];
        }
    }

    printf("%d\n", score);

    return 0;
}
