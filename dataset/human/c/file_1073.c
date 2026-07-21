#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
int main(void){
    int num,map[4],i,o;
    char mapc[4]="mcxi",line1[9],line2[9];
    scanf("%d",&num);
    for(o=0;o<num;o++){
        memset(map,0,sizeof(map));
        scanf("%s %s",line1,line2);
        i=0;
        while(line1[i]){
            if('0'<=line1[i] && line1[i] <= '9'){
                if(line1[i+1] == 'm')
                    map[0]+=line1[i]-48;
                if(line1[i+1] == 'c')
                    map[1]+=line1[i]-48;
                if(line1[i+1] == 'x')
                    map[2]+=line1[i]-48;
                if(line1[i+1] == 'i')
                    map[3]+=line1[i]-48;
                i++;
            }
            else{
                if(line1[i] == 'm')
                    map[0]+=1;
                if(line1[i] == 'c')
                    map[1]+=1;
                if(line1[i] == 'x')
                    map[2]+=1;
                if(line1[i] == 'i')
                    map[3]+=1;
            }
            i++;
        }i=0;
        while(line2[i]){
            if('0'<=line2[i] && line2[i] <= '9'){
                if(line2[i+1] == 'm')
                    map[0]+=line2[i]-48;
                if(line2[i+1] == 'c')
                    map[1]+=line2[i]-48;
                if(line2[i+1] == 'x')
                    map[2]+=line2[i]-48;
                if(line2[i+1] == 'i')
                    map[3]+=line2[i]-48;
                i++;
            }
            else{
                if(line2[i] == 'm')
                    map[0]+=1;
                if(line2[i] == 'c')
                    map[1]+=1;
                if(line2[i] == 'x')
                    map[2]+=1;
                if(line2[i] == 'i')
                    map[3]+=1;
            }
            i++;
        }
        for(i=3;i>=0;i--){
            if(map[i] >= 10){
                map[i-1]++;
                map[i]%=10;
            }
        }
        for(i=0;i<4;i++){
            if(map[i] == 1)
                printf("%c",mapc[i]);
            else if(map[i] != 0)
                printf("%d%c",map[i],mapc[i]);
        }
        printf("\n");
    }
    return 0;
}
