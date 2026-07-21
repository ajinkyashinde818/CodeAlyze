#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<malloc.h>
#include<math.h>
#include<x86intrin.h>


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

void InputIntAry(int *a,int nDigit,int N){      //nDigitは想定される最大桁数
    char *buf,*ptr;

    buf=(char*)malloc( (N*(nDigit+2)) * sizeof(char) );
    my_gets(buf,N*(nDigit+2),stdin);

    ptr=strtok(buf," ");
    while(ptr!=NULL && N-->0){
        *(a++)=atoi(ptr);
        ptr=strtok(NULL," ");
    }
    free(buf);
}

int CmpInt(const void *a, const void *b){        //b-aを返す(qsortなら4321)
    return *((int*)b)- *((int*)a);
}


int main(){
    int N,Satis=0;
    int A[20]={},B[20]={},C[20]={};

    scanf("%d%*c",&N);
    InputIntAry(A,10,N);
    InputIntAry(B,10,N);
    InputIntAry(C,10,N-1);

    int Prev=-100;
    for(int i=0;i<N;i++){
        Satis += B[A[i]-1];
        if(Prev == A[i]-1){
            Satis += C[Prev-1];
        }
        Prev = A[i];
    }
    printf("%d\n",Satis);

    return 0;
}
