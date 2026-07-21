#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LINE_BUF_SIZE 100

int main(){

    int i,j,k;
    int max = 0;
    int count = 0;
    int M,N,v;
    int D,X;
    char line[LINE_BUF_SIZE];

    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d", &N);

    int A[N+1];

    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d %d", &D,&X);

//    printf("n,d,x=%d %d %d\n",N,D,X);

    for(i=1;i<=N;i++){

        fgets(line,sizeof(line),stdin);
        sscanf(line,"%d", &v);
        //printf("v=%d\n",v);
        A[i] = v;
    }

    int num = 0;
    count = 0;

    for(j=1;j<=N;j++){
        for(i=1;i<=D;i++){
            if(i == count*A[j]+1){
                num += 1;
                count += 1;
            }
            //count = 0;
        //printf("num=%d\n",num);
        }
        count = 0;
    }

    printf("%d",X+num);

    return 0;

}
