#include <stdio.h>
#include <string.h>

static bool is_solved(char cube[30])
{
    for (int i = 1; i < 9; i++)
    {
        if (cube[i] != cube[0]) return false;
        if (cube[21 + i] != cube[21]) return false;
    }
    if (cube[9] != cube[10] || cube[10] != cube[11]) return false;
    if (cube[12] != cube[13] || cube[13] != cube[14]) return false;
    if (cube[15] != cube[16] || cube[16] != cube[17]) return false;
    if (cube[18] != cube[19] || cube[19] != cube[20]) return false;
    return true;
}

#define SWAP(a, b) {char temp = (a); (a) = (b); (b) = temp;}

static void flip_up(char cube[30])
{
    SWAP(cube[0], cube[27])
    SWAP(cube[1], cube[28])
    SWAP(cube[2], cube[29])
    SWAP(cube[14], cube[15])
    SWAP(cube[18], cube[20])
}

static void flip_down(char cube[30])
{
    SWAP(cube[6], cube[21])
    SWAP(cube[7], cube[22])
    SWAP(cube[8], cube[23])
    SWAP(cube[12], cube[17])
    SWAP(cube[9], cube[11])
}

static void flip_left(char cube[30])
{
    SWAP(cube[0], cube[23])
    SWAP(cube[3], cube[26])
    SWAP(cube[6], cube[29])
    SWAP(cube[9], cube[20])
    SWAP(cube[15], cube[17])
}

static void flip_right(char cube[30])
{
    SWAP(cube[2], cube[21])
    SWAP(cube[5], cube[24])
    SWAP(cube[8], cube[27])
    SWAP(cube[12], cube[14])
    SWAP(cube[11], cube[18])
}

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int solve(char cube[30], int iteration)
{
    if (iteration >= 9) return 9;

    char cU[30], cD[30], cL[30], cR[30];
    memcpy(cU, cube, 30);
    memcpy(cD, cube, 30);
    memcpy(cL, cube, 30);
    memcpy(cR, cube, 30);

    flip_up(cU);
    flip_down(cD);
    flip_left(cL);
    flip_right(cR);

    if (is_solved(cU))
        return iteration;
    if (is_solved(cD))
        return iteration;
    if (is_solved(cL))
        return iteration;
    if (is_solved(cR))
        return iteration;

    int min_iteration = solve(cU, iteration + 1);
    min_iteration = min(min_iteration, solve(cD, iteration + 1));
    min_iteration = min(min_iteration, solve(cL, iteration + 1));
    min_iteration = min(min_iteration, solve(cR, iteration + 1));

    return min_iteration;
}

int main(int argc, const char *argv[])
{
    int N;
    scanf("%d", &N);

    while (N-- > 0)
    {
        char cube[30];

        for (int i = 0; i < 30; i++)
        {
            scanf("%hhd", &cube[i]);
        }

        int ans = 0;

        if (!is_solved(cube))
        {
            ans = solve(cube, 1);
        }

        printf("%d\n", ans);
    }
    return 0;
}
