#include <stdio.h>
#define HMAX 52
#define WMAX 52
int main(void) {
    char grid[HMAX][WMAX];
    int h, w, i, j, cnt=0;
    char newline[HMAX];
    scanf("%d %d", &h, &w);
    scanf("%c", &newline[0]);
    for(i=1; i<=h; i++) {
        for(j=1; j<=w; j++) {
            scanf("%c", &grid[i][j]);
        }
        scanf("%c", &newline[i]);
    }
    
    for(i=1; i<=h; i++) {
        for(j=1; j<=w; j++) {
            if(grid[i][j]=='#') {
                if(grid[i][j]!=grid[i][j-1] && grid[i][j]!=grid[i-1][j]
                   && grid[i][j]!=grid[i][j+1] && grid[i][j]!=grid[i+1][j])
                    cnt++;
            }
        }
    }
    if(cnt>0)
        printf("No");
    else
        printf("Yes");
    return 0;
}
