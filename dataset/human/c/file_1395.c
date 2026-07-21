#include <stdio.h>
int main(void){
    int n,m;
    int a[200000]={0};
    int b[200000]={0};
    int c[200000]={0};
    int d[200000]={0};
    int i,j;
    int flag = 0;
    int cnt = 0;
    int cnt_b = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<m;i++){
        if(a[i] == 1){
            c[b[i]]++;
        }
    }
    for(i=0;i<m;i++){
      if(b[i] == n){
        c[a[i]]++;
      }
    }
    for(i=0;i<200000;i++){
      if(c[i] >= 2){
        printf("POSSIBLE");
        return 0;
      }
    }
    printf("IMPOSSIBLE");
    return 0;
}
