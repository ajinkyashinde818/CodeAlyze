#include <stdio.h>
#define N 52

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    char s[N][N] = {{0}};
    for (int i = 1; i <= H; i++)
       scanf("%s", s[i] + 1);

    for (int i = 1; i <= H; i++)
       for (int j = 1; j <= W; j++)
          if (s[i][j] == '#' && s[i][j+1] != '#' && s[i][j-1] != '#'
                  && s[i-1][j] != '#' && s[i+1][j] != '#') {
              printf("No\n");
              return 0;
          }

    printf("Yes\n");
    return 0;
}
