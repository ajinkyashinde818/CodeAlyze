#include<stdio.h>
#include<stdint.h>
#include<limits.h>
#define min(lhs,rhs) ((rhs)<(lhs)?(rhs):(lhs))

int main(void){
    register int i,j;
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    int c[n],a[n][m];
    for(i = 0;i < n;i++){
        scanf("%d",&c[i]);
        for(j = 0;j < m;j++)scanf("%d",&a[i][j]);
    }
    long amin = LONG_MAX;
    uint16_t bits[n],maxb = 0,curb;
    bits[0] = 1u;
    for(i = 1;i < n;i++)bits[i] = bits[i-1] << 1;
    for(i = 0;i < n;i++)maxb += bits[i];
    long cux[m],curm;
    int flag;
    for(curb = 0u;curb <= maxb;curb++){
        curm = 0;
        flag = 1;
        for(i = 0;i < m;i++)cux[i] = 0;
        for(i = 0;i < n;i++)if(curb & bits[i]){
            curm += c[i];
            for(j = 0;j < m;j++)cux[j] += a[i][j];
        }
        for(i = 0;i < m;i++)if(cux[i] < x)flag = 0;
        if(!flag)continue;
        amin = min(amin,curm);
    }
    printf("%ld",amin == LONG_MAX ? -1 : amin);
}
