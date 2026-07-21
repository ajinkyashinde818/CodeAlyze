#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
    long N;
    int i,p;
    long a[100001] = {0};
    long count = 0;
    long pp[100001] = {1};

    scanf("%ld", &N);

    for (i = 1; i <= N; i++) {
        scanf("%ld", &a[i]);
    }

    i = 1;
    pp[i++] = p = a[1];
    count++;

    if (p == 2) {
        printf("%ld", count);
        return 0;
    }

    while (1) {
        
       pp[i++] = p = a[p];
       count++;

       if (p == 2)
           break;

       for (int j = 0; j < i - 1; j++) {
           if (p == pp[j]) {
               printf("-1");
               return 0;
           }
       }
       


    }

    printf("%ld", count);

    return 0;

}
