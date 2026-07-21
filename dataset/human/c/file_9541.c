#include<stdio.h>
int main()
{
    int man,day,amari;
    int choco = 0;
    scanf("%d",&man);
    scanf("%d",&day);
    scanf("%d",&amari);
    int temp = 0;
    for(int i = 0;i < man;i++){
        scanf("%d",&temp);
        if(temp > day){
            choco += 1;
        }
        else if(day % temp == 0){
            choco += (day / temp);
        }
        else{
            choco += (day / temp + 1);
        }
    }
    choco += amari;   
    printf("%d\n",choco);
    return 0;
}
