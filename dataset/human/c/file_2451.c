#include<stdio.h>

int main(){
        char mojiretsu[3];
        scanf("%s",mojiretsu);
        int x,i;
        if(mojiretsu[0] != mojiretsu[1] && mojiretsu[1] != mojiretsu[2] && mojiretsu[2] != mojiretsu[0]){                                                                                     
                for(i=0;i<3;i++){
                        if(mojiretsu[i] == 'a'){
                                x++;
                                continue;
                        }else if(mojiretsu[i] == 'b'){
                                x++;
                                continue;
                        }else if(mojiretsu[i] == 'c'){
                                x++;
                                continue;
                        }else   break;
                }
        }
        if(x == 3)      printf("Yes");
        else            printf("No");
        return(0);
}
