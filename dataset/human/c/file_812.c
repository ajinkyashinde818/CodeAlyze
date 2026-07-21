#include<stdio.h>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define ll long long

int d, g, arr[99]={}, flg[99]={}, c[11], p[11], ans = 1001001001; 

void nya(int n){
    if(n == d){
        int sum = 0, score = 0;
        for(int i=0; i<d; i++){
            if((arr[i]+1)*100*p[arr[i]] <= g - score){
                score += (arr[i]+1)*100*p[arr[i]] + c[arr[i]];
                sum += p[arr[i]];
            }else {
                int tmp = (g-score + (arr[i]+1)*100 - 1) / ((arr[i]+1)*100);
                sum += tmp;
                score += tmp * (arr[i]+1) * 100;
            }
            if(score >= g){
                ans = min(ans, sum);
                break;
            }
        }
        return;
    }
    for(int i=0; i<d; i++){
        if(!flg[i]){
            flg[i] = 1;
            arr[n] = i;
            nya(n + 1);
            flg[i] = 0;
        }
    }
    return;
}

int main(){
    scanf("%d%d", &d, &g);
    for(int i=0; i<d; i++){
        scanf("%d%d", &p[i], &c[i]);
    }
    nya(0);
    printf("%d\n", ans);
    return 0;
}
