#include <stdio.h>
int main(void){
    unsigned long int n,half,denomi,i,ans=0;
    scanf("%ld",&n);
    if(n%2==1){
        printf("0");
        return 0;
    };
    half=n/2;
    denomi=1;
    for(i=1;i<26;i++){
        denomi*=5;
        ans+=half/denomi;
        //printf("found= %ld; ans= %ld \n",half/denomi, ans);        
    };
    printf("%ld",ans);
    return 0;
};
