#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
    static int i=0;
    int len=(int)strlen(str);
    char tmp;
    if(i>=len/2) return;
    tmp=str[i];
    str[i]=str[len-1-i];
    str[len-1-i]=tmp;
    i++;
    reverse(str);
}

char *divide[4]={"maerd","remaerd","esare","resare"};
char d[8],cpy[8];
int main(void)
{
    char S[100000];
    scanf("%s",S);
    reverse(S);//文字列反転
   
    int can=1;
    for(int k=0;S[k]!='\0';){
        int can2=0;
        for(int j=0;j<4;j++){
            strncpy(cpy,S+k,strlen(divide[j]));
            cpy[strlen(divide[j])]='\0';
            if(strcmp(cpy,divide[j])==0){
                can2=1;
                k+=strlen(divide[j]);
            }
        }
        if(can2==0){
            can=0;
            break;
        }
    }
    if(can==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
