#include<stdio.h>
#include<string.h>
 
#define N 100000

int q;
char s[3*N];

int main(){
    scanf("%s",s);
    scanf("%d",&q);
    int slen = strlen(s);
    int t, sMin=2*N, sMax=sMin+slen-1, reverse=0; 
    char f, c, sMod[5*N];

    strncpy(sMod+sMin, s, slen);
    for (int i = 0; i < q; i++){
        scanf("%d",&t);
        if(t==1){
            reverse = (reverse+1)&1;
        }
        else{
            scanf("%d %c", &f, &c);    //　型がごちゃごちゃ
            if(f==1){
            //先頭にc
                if(reverse==0){
                    sMin--;
                    sMod[sMin] = c;
                }
                else{
                    sMax++;
                    sMod[sMax] = c;
                }
            }
            else{
            //末尾にc
                if(reverse==0){
                    sMax++;
                    sMod[sMax] = c;
                }
                else{
                    sMin--;
                    sMod[sMin] = c;
                }
            }
        }
    }
    if(reverse==0){
        strncpy(s, sMod+sMin, sMax-sMin+1 );
    }
    else{
        int cnt = 0;
        for(int i = sMax; i>=sMin; i--){
            s[cnt] = sMod[i];
            cnt++;
        }
    }
    slen = strlen(s);
    s[slen] = '\0';
        
    printf("%s\n", s);
    return 0;
}
