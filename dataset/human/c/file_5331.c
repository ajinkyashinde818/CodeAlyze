#include <stdio.h>
#include <stdlib.h>

typedef struct _book_
{
    unsigned price;
    unsigned *level;
} book;

book *scan_books(unsigned N, unsigned M)
{
    book *b = malloc(sizeof(book) * N);
    for (size_t i = 0; i < N; i++)
    {
        b[i].level = malloc(sizeof(unsigned) * M);
        scanf("%u", &b[i].price);
        for (size_t j = 0; j < M; j++)
        {
            scanf("%u", &b[i].level[j]);
        }
    }
    return b;
}

int main(int argc, char const *argv[])
{
    unsigned N, M, X;
    scanf("%u %u %u", &N, &M, &X);
    book *books = scan_books(N, M);

    unsigned limit = 1;
    limit <<= N;
    unsigned *combi = malloc(sizeof(unsigned) * limit);

    unsigned lowest_cost = 4294967295;
    for (unsigned i = 0; i < limit; i++)
    {
        unsigned combi = i;
        unsigned cost_sum = 0;
        unsigned *level_sum = calloc(M, sizeof(unsigned));
        for (size_t j = 0; j < N; j++)
        {
            if (combi & 1)
            {
                cost_sum += books[j].price;
                for (size_t k = 0; k < M; k++)
                {
                    level_sum[k] += books[j].level[k];
                }
            }
            combi >>= 1;
        }
        for (size_t j = 0; j < M; j++)
        {
            if (level_sum[j] < X)
            {
                goto CONTINUE;
            }
        }

        lowest_cost = lowest_cost > cost_sum ? cost_sum : lowest_cost;
        CONTINUE: continue;
    }

    if (lowest_cost == 4294967295)
    {
        printf("-1\n");
    } else
    {
        printf("%u\n", lowest_cost);
    }

    return 0;
}
