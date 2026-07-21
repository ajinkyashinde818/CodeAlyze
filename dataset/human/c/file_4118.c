#include<stdio.h>
int main(){
    int a,b,k;
    int i,j=0,tmp;
    int common[101];
    scanf("%d%d%d",&a,&b,&k);
    tmp=a;
    if(a>b)tmp=b;
    for(i=tmp;i>=1;i--){
        if(a%i==0&&b%i==0){
            common[j]=i;
            j++;
        }
    }
    printf("%d\n",common[k-1]);
    return 0;
}
