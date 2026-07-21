#include<stdio.h>
#include<stdlib.h>

int acount;
int bcount;
int ccount;
int dec(char, char, int);

void main(int argc, char *argv[]){
    char buf[130];
    char S[3] = "abc";
    int ok;
    int okcount;

    if(scanf("%c %c %c", &buf[0], &buf[1], &buf[2]) < 3){
        exit(1);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ok = dec(S[i], buf[j], i);
            if(ok == 1){
                okcount++;
                break;
            }
        }
    }

    if(okcount == 3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}

int dec(char a,char b, int i){
    if(a == b){
        if(i == 0, acount == 0){
            acount++;
            return 1;
        }else if(i == 1, bcount == 0){
            bcount++;
            return 1;
        }else if(i == 2, ccount == 0){
            ccount++;
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
