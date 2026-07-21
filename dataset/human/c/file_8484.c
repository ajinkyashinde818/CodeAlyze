#include <stdio.h>
#define W 5
#define H_MAX 10
#define THRESHOLD 3
#define EMPTY -1

int field[W + 1][H_MAX];
int h;

int main(void)
{
    int x, y, i, stable, score;

    for(y = 0; y < H_MAX; y++)
        field[W][y] = EMPTY;

    while(scanf("%d", &h), h)
    {
        for(y = 0; y < h; y++)
            for(x = 0; x < W; x++)
                scanf("%d", &field[x][y]);

        stable = score = 0;

        while(!stable)
        {
            stable = 1;
            for(y = 0; y < h; y++)
                for(x = i = 0; x < W; x++)
                {
                    i++;
                    if(field[x][y] != field[x + 1][y])
                    {
                        if(i >= THRESHOLD && field[x][y] != EMPTY)
                        {
                            stable = 0;
                            score += field[x][y] * i;
                            while(i--) field[x - i][y] = EMPTY;
                        }
                        i = 0;
                    }
                }

            for(x = 0; x < W; x++)
                for(y = h - 1; y > 0; y--)
                    if(field[x][y] == EMPTY)
                    {
                        for(i = y; field[x][i] == EMPTY && i > 0; i--);
                        field[x][y] = field[x][i];
                        field[x][i] = EMPTY;
                    }
        }

        printf("%d\n", score);
    }

    return 0;
}
