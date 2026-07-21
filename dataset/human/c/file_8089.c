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
    int A,B,C,D;

    scanf("%d %d %d %d%*c",&A,&B,&C,&D);
    printf("%d\n",(A*B>C*D)?(A*B):C*D);
    return 0;
}
