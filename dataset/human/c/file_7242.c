#include<stdio.h>

char mark[2][2] = {{'#', '.'}, {'.', '#'}};
void draw_rect(int h, int w)
{
int i, j;
for(i=0;i<h;i++){
for(j=0;j<w;j++){
printf("%c",mark[i&1][j&1]);
}
printf("\n");
}
}

int main(void)
{
int h, w;

while(1){
scanf("%d %d", &h, &w);
if(!(h|w)) break;
draw_rect(h, w);
printf("\n");
}

return 0;
}
