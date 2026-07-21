#include<stdio.h>
int main(void){
    int menunum;
    int menu[100];
    int satisfy[100];
    int extra[100];
    int ans=0;
    int num;

    scanf("%d",&menunum);

    for(int n=0;n<menunum;n++){
        scanf("%d",&menu[n]);
    }
    for(int m=0;m<menunum;m++){
        scanf("%d",&satisfy[m]);
    }
    for(int o=0;o<menunum-1;o++){
        scanf("%d",&extra[o]);
    }
    num=menu[0]-1;
    ans=ans+satisfy[num];
    for(int i=1;i<menunum;i++){
        num=menu[i]-1;
        ans=ans+satisfy[num];
        if(menu[i]==menu[i-1]+1){
            ans=ans+extra[num-1];
        }
    }

    printf("%d",ans);


    return 0;
}
