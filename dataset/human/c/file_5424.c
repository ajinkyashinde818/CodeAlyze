#include <stdio.h>
 
int myabs(int a) {
    return a<0?-a:a;
}
 
int mymax(int a,int b) {
    return a>=b?a:b;
}
 
int getCost(int sx,int sy,int tx,int ty) {
    int dx=myabs(sx-tx);
    int dy=myabs(sy-ty);
    if((sx-tx)*(sy-ty)>=0) {
        return mymax(dx,dy);
    } else {
        return dx+dy;
    }
}
 
int main(void) {
    int N,i;
    int x,y;
    int answer=0;
    scanf("%*d%*d%d",&N);
    scanf("%d%d",&x,&y);
    for(i=1;i<N;i++) {
        int next_x,next_y;
        scanf("%d%d",&next_x,&next_y);
        answer+=getCost(x,y,next_x,next_y);
        x=next_x;
        y=next_y;
    }
    printf("%d\n",answer);
    return 0;
}
