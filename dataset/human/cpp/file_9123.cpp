#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;

int main(){
    int i,j,s,t,n,m;
    cin>>n;
    cin>>m;
    char picturea[n][n];
    char pictureb[m][m];
    for(i=0;i<n;i++) scanf("%s",picturea[i]);
    for(i=0;i<m;i++) scanf("%s",pictureb[i]);

    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",picturea[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf("%c",pictureb[i][j]);
        }
        printf("\n");
    }*/
    int k=n-m;//k=1
    int ct=0;
    int hantei=0;

    for(s=0;s<=k;s++){//0~1
        for(t=0;t<=k;t++){//0~1
            ct=0;
            if(picturea[s][t]!=pictureb[0][0]) ct=1;

            if(picturea[s][t]==pictureb[0][0]){
                for(i=0;i<m;i++){//s=0 0~1 s=1 1~2
                    for(j=0;j<m;j++){
                        if(picturea[i+s][j+t]!=pictureb[i][j]) ct++;
                    }
                }
            }
            if(ct==0)  hantei=1;
        }
    }
    if(hantei==0) printf("No\n");
    else printf("Yes\n");


    return 0;
}
