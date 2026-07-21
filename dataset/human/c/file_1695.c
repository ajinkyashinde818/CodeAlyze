#include<stdio.h>

int main (void)
{
    int N,i;
    int a[20];
    int b[20];
    int c[20];
    int val;
    char bin;
    int satisfy = 0;

//はいんねえ

    scanf("%d",&N);
    scanf("%c",&bin);

    for(i=0;i<N;i++){
        scanf("%d ",&a[i]);
        //printf("got %d\n",a[i]);
        //scanf("%c",&bin);
    }


    for(i=0;i<N;i++){
        scanf("%d ",&b[i]);
        //printf("b got %d\n",b[i]);
        //scanf("%c",&bin);
    }


    for(i=0;i<N-1;i++){
        scanf("%d",&c[i]);
        //printf("got %d\n",c[i]);
        scanf("%c",&bin);
    }

    //printf("sty:%d\n",satisfy);

    for(i=0;i<N;i++){
        satisfy+=b[a[i]-1];
        //printf("wii add %d\n",b[a[i]-1]);
        if(i==0){

        }else if(a[i-1]+1 == a[i]){
            //printf("add c:%d",c[a[i-1]-1]);
            satisfy+=c[a[i-1]-1];
        }

        //printf("now sty %d\n",satisfy);
    }

    printf("%d",satisfy);





    return 0;
}
