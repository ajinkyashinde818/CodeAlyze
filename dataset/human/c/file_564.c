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

int myMatch(char A[100][100], char B[100][100], int N, int M, int i, int j){
    for(int k=0;k<M;k++){
        if(memcmp(A[i+k]+j,B[k],M))
            return 1;
    }
    return 0;
}


int main(void){
    int N,M;
    char A[100][100]={},B[100][100]={};

    scanf("%d %d%*c",&N,&M);
    for(int i=0;i<N;i++){
        my_gets(A[i],100,stdin);
    }
    for(int i=0;i<M;i++)
        my_gets(B[i],100,stdin);
    
    for(int i=0; i <= N-M; i++){
        char *ptr=A[i];

        //printf("i:%d\n",i);
        while((ptr=strstr(ptr,B[0]))!=NULL ){
            if(myMatch(A, B, N, M, i, (int)(ptr-A[i])) == 0){
                puts("Yes");
                return 0;
            }
            ptr++;
        }
    }
    puts("No");

    return 0;
}
