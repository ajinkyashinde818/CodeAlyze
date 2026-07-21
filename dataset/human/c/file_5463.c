#include<stdio.h>
int main(void){
    int w,h,n,x,y,nowx,nowy,ans=0,i,dx,dy;
    scanf("%d %d %d",&w,&h,&n);
    scanf("%d %d",&nowx,&nowy);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
        dx=x-nowx;
        dy=y-nowy;
        if(dx*dy>=0){
            if(dx<0)dx=dx*-1;
            if(dy<0)dy=dy*-1;
            if(dx>dy){
                ans+=dx;
            }else{
                ans+=dy;
            }
        }else{
            if(dx<0)dx=dx*-1;
            if(dy<0)dy=dy*-1;
            ans+=dx+dy;
        }
        nowx=x;
        nowy=y;
    }
    printf("%d\n",ans);
    return 0;
}
