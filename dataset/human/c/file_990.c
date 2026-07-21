#include<stdio.h>
int main(void){
    int E,Y;
    scanf("%d %d",&E,&Y);
    if(E==0){
        if(Y>=1868 && Y<=1911){
            printf("M%d\n",Y-1868+1);
        }else if(Y>=1912 && Y<=1925){
            printf("T%d\n",Y-1912+1);
        }else if(Y>=1926 && Y<=1988){
            printf("S%d\n",Y-1926+1);
        }else if(Y>=1989 && Y<=2016){
            printf("H%d\n",Y-1989+1);
        }
    }else if(E==1){
        printf("%d\n",Y+1868-1);
    }else if(E==2){
        printf("%d\n",Y+1912-1);
    }else if(E==3){
        printf("%d\n",Y+1926-1);
    }else if(E==4){
        printf("%d\n",Y+1989-1);
    }
    return 0;
}
