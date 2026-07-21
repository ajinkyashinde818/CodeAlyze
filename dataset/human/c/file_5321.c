#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main(void){
    int n,m,x,i,j,ans,cost=100000000,und[15]={},k[15]={},flag=0,c[15]={},a[15][15]={};
    scanf("%d %d %d\n",&n,&m,&x);
    for(i=1; i<=n; i++){
        scanf("%d",&c[i]);
        for(j=1; j<=m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(k[1]=0;k[1]<=1;k[1]++){
        for(k[2]=0;k[2]<=1;k[2]++){
            for(k[3]=0;k[3]<=1;k[3]++){
                for(k[4]=0;k[4]<=1;k[4]++){
                    for(k[5]=0;k[5]<=1;k[5]++){
                        for(k[6]=0;k[6]<=1;k[6]++){
                            for(k[7]=0;k[7]<=1;k[7]++){
                                for(k[8]=0;k[8]<=1;k[8]++){
                                    for(k[9]=0;k[9]<=1;k[9]++){
                                        for(k[10]=0;k[10]<=1;k[10]++){
                                            for(k[11]=0;k[11]<=1;k[11]++){
                                                for(k[12]=0;k[12]<=1;k[12]++){
                                                    for(i=1; i<=n; i++){
                                                        for(j=1; j<=m; j++){
                                                            und[j]+=a[i][j]*k[i];
                                                        }
                                                    }
                                                    for(j=1; j<=m; j++){
                                                        if(und[j]<x)flag=1;
                                                    }
                                                    
                                                    for(j=1; j<=14; j++){
                                                        und[j]=0;
                                                    }
                                                    if(flag==0){
                                                        for(i=1; i<=n; i++){
                                                            ans+=c[i]*k[i];
                                                        }
                                                        cost=min(ans,cost);
                                                    }
                                                    ans=0;
                                                    flag=0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(cost==100000000){
        printf("-1");
        return 0;
    }
    printf("%d",cost);
    return 0;
}
