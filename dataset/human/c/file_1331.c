#include<stdio.h>
int main(void){
    unsigned long long int n,m;
    unsigned long long int a[2000000],b[2000000];
    scanf("%llu %llu",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%llu %llu",&a[i],&b[i]);
    }
    unsigned long long int f1go[2000000]={},fngo[2000000]={};
    for(int i=0;i<m;i++){
        if(a[i]==1){
            f1go[b[i]]=1;
        }
        if(b[i]==n){
            fngo[a[i]]=1;
        }
    }
    if(m==1){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i=0;i<=n;i++){
        if(f1go[i]==fngo[i]&&f1go[i]==1){
            printf("POSSIBLE\n");
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
