#include <stdio.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int main(){
    int h,w;scanf("%d%d",&h,&w);
    char c[55][55];
    rep(i,h) scanf("%s",&c[i]);
    int ang=0;
    rep(i,h){
        rep(j,w){
            if(c[i][j]=='.') continue;
            int ng=1;
            rep(k,4){
                int tmpi=i+dx[k];
                int tmpj=j+dy[k];
                if(tmpi>=0&&tmpi<h&&tmpj>=0&&tmpj<w){
                    if(c[tmpi][tmpj]=='#') ng=0;
                }
            }
            if(ng) {
                ang=1;
                break;
            }
        }
        if(ang) break;
    }

    if(ang) puts("No");
    else puts("Yes");
}
