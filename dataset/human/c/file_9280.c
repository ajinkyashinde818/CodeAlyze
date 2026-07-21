#include <stdio.h>
int main(void)
{
    int n, k;
    if (scanf("%d %d", &n, &k) == EOF) {
        printf("Failed to read integer.\n");
        return -1;
    }

    int member[n];
    int count = 0;
    for(int i = 0; i < n; i++){
        if (scanf("%d", &member[i]) != EOF) {
            count += (member[i] >= k) ? 1 : 0;
        } else {
            printf("Failed to read integer.\n");
            return -1;
        }
    }
    printf("%d\n", count);
    return 0;
}
