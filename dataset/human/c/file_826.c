#include <stdio.h>
int main(void){
    int d,g,i,j,k;
    long long ans=100000;
    scanf("%d %d",&d,&g);
    int p[d],c[d];
    for(i=0;i<d;i++) scanf("%d %d",&p[i],&c[i]);
    for(i=0;i<(1<<d);i++){
        long long cnt=0,tmp=0;
        for(j=0;j<d;j++){
            if(i&(1<<j)){
                tmp += 100*p[j]*(j+1)+c[j];
                cnt += p[j];
            }
        }
        if(g<=tmp){
            if(cnt<ans) ans=cnt;
        }
        else{
            for(j=d-1;j>=0;j--){
                if(i&(1<<j)) continue;
                else{
                    for(k=0;k<p[j];k++){
                        if(tmp>=g) break;
                        tmp+=100*(j+1);
                        cnt++;
                    }
                }
            }
        }
        if(cnt<ans) ans=cnt;
    }
    printf("%lld",ans);
}
