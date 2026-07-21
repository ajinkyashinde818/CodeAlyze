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
    long long x,cnt=0;

    scanf("%lld",&x);

    cnt += 2*(x/11);
    x %= 11;
    if(x==0)
        cnt+=0;
    else if(x<= 6)
        cnt+=1;
    else
    {
        cnt+=2;
    }
    printf("%lld\n",cnt);
}
