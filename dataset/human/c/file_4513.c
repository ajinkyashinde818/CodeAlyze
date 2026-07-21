#include<stdio.h>

int main (void){

    int d[100][2];
    int n,zoro,flag;
    char c;

    scanf("%d",&n);
    scanf("%c",&c);

    zoro=0;
    flag=0;

    for(int i=0;i<n;i++){
        scanf("%d %d",&d[i][0],&d[i][1]);
        scanf("%c",&c);

        if(d[i][0]==d[i][1]){
            zoro++;
            if(zoro>2){
                flag=1;
            }
        }else{
            zoro=0;
        }
    }

    if(flag==1){
        printf("Yes");
    }else{
        printf("No");
    }






    return 0;
}
