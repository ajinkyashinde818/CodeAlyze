#include <stdio.h>
int main(void) {
    char grid[52][52];
    int h, w, i, j, cnt=0;
    scanf("%d %d", &h, &w);
    for(i=1; i<=h; i++)
      	scanf("%s", &grid[i]);
    
  	for(i=1; i<=h; i++) {
        for(j=1; j<=w; j++) {
            if(grid[i][j]=='#') {
                if(grid[i][j]!=grid[i][j-1] && grid[i][j]!=grid[i-1][j] && grid[i][j]!=grid[i][j+1] && grid[i][j]!=grid[i+1][j])
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
