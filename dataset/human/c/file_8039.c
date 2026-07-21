#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,l,r) for(ll i=l;i<(ll)(r);i++) //ll
#define max(l,r) ((l)>(r)?l:r)
#define min(l,r) ((l)<(r)?l:r)
#define swap(l,r) {ll tp=l;l=r;r=tp;}
const ll MOD = 1000000007;
const int INF = (1<<30);
int upcmpii(const void *a, const void *b){return(*(int*)a==*(int*)b?0:(*(int*)a>*(int*)b?1:-1));}
void sort_ui(int*a, int n){qsort(a,n,sizeof(int),upcmpii);}

int H,W;
int sx,sy,gx,gy;
char s[1010][1010];
int cnt[1010][1010] = {0};
ll ans = 0;
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int qxf = 0, qxb = 0, quex[101010101];
int qyf = 0, qyb = 0, quey[101010101];

void dfs(int cx,int cy){
    cnt[cx][cy] = ans+1;
    rep(i,4){
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W){
            if(cnt[nx][ny] <= 0 && s[nx][ny] == '.'){
                dfs(nx,ny);
            }
        }
    }
    rep(i,5) rep(j,5) {
        int nx = cx-2+i;
        int ny = cy-2+j;
        if(nx >= 0 && nx < H && ny >= 0 && ny < W){
            if(cnt[nx][ny] == 0 && s[nx][ny] == '.'){
                cnt[nx][ny] = -1;
                quex[qxb++] = nx;
                quey[qyb++] = ny;
            }
        }
    }
}

void solve(){
    dfs(sx,sy);
    while(cnt[gx][gy] <= 0){
        ans++;
        int m = qxb-qxf;
        int tmp = 0;
        rep(i,m){
            int nnx = quex[qxf++],nny = quey[qyf++];
            if(cnt[nnx][nny] == -1) { dfs(nnx,nny); tmp++; }
        }
        if(tmp == 0 && cnt[gx][gy] == 0){
            ans = -1;
            break;
        }
    }
}

int main(){
    scanf("%d%d", &H,&W);
    scanf("%d%d%d%d", &sx,&sy,&gx,&gy);
    sx--;sy--;gx--;gy--;
    rep(i, H) scanf("%s", s[i]);

    solve();

    printf("%lld", ans);
}
