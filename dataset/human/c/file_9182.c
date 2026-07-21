#include <stdio.h>

#ifdef DEBUG
#define DPRTF(x) printf x
#define TRACE (printf("%s:%s:%d\n", __FILE__, __func__, __LINE__))
#define ERR(x) (TRACE, (x))
#else
#define DPRTF(x)
#define TRACE
#define ERR(x) (x)
#endif

int main(int argc, char *argv[])
{
    int N = 0;
    int K = 0;
    int h[100000];
    int count = 0;

    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }

    for (int j = 0; j < N; j++) {
        if (h[j] >= K) {
            count++;
        }
    }

    printf("%d\n", count);
    
    return 0;
}
