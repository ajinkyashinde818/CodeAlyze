#include<stdio.h>
#include<math.h>
int ho[100010];
long long int str[100010];
int main(void){
    int n,m,i,temp;
    for(i=0;i<100010;i++){
        ho[i]=0;
        str[i]=0;
    }
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&temp);
        ho[temp]=1;
        if(i!=0 && ho[temp-1]==1){
            printf("0\n");
            return 0;
        }
    }
    str[0]=1;
    str[1]=1;
    if(ho[1]==1){
        str[1]=0;
    }
    for(i=2;i<100010;i++){
        str[i]=str[i-1]+str[i-2];
        str[i]=str[i]%1000000007;
        if(ho[i]==1){
            str[i]=0;
        }
    }
    printf("%lld\n",str[n]%1000000007);
    return 0;
}
