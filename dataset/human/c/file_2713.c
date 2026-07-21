#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

int my_gets(char *buf,int nBuf,FILE *fp){
    int ch;

    while(--nBuf >0){
        ch=getc(fp);
        if(ch==EOF || ch=='\n')
            break;
        *(buf++)=(char)ch;
    }
    *(buf)='\0';

    return nBuf;
}

int main(void){
    int K,S,cnt=0;

    scanf("%d %d%*c",&K,&S);
    for(int X=0; X<=K; X++){
        int M=S-X;
        //Y+Z = M
        if(M >= 0 && M<= K)
            cnt += M+1;
        else if(M > K && M <= 2*K)
            cnt += M+1 - 2*( M-K );
        else
            cnt+= 0;
    }
    printf("%d\n",cnt);
}
