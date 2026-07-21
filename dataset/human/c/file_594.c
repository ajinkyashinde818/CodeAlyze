#include <stdio.h>

int match(char a[51][51],char b[51][51],int m,int I,int J){
    int i,j;
    for(i=0;i<m;i++)for(j=0;j<m;j++){
        if(b[i][j]!=a[i+I][j+J]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,m,i,j,yes=0,area;
    scanf("%d %d",&n,&m);
    
    char a[51][51],b[51][51];
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<m;i++)scanf("%s",b[i]);

    area = n-m;
    for(i=0;i<=area;i++)for(j=0;j<=area;j++){
        if(a[i][j]==b[0][0]){
            yes=match(a,b,m,i,j);
            if(yes==1)goto OUT;
        }
    }
    OUT:
    if(yes==1)printf("Yes\n");
    else printf("No\n");
    return 0;
}
