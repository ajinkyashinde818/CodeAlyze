#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 500000
#define BUF 200000 
bool reverse = false;
int main(){
    char S[MAX];
    scanf("%s",S);
    int Q;
    int length=strlen(S);
    int back = 1;
    for(int i=0;i<length;i++){
        S[i+BUF]=S[i];
        S[i]='\0';
    }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        int q;
        scanf("%d",&q);
        if(q==1){
            if(reverse)
                reverse = false;
            else
                reverse = true;
        }
        else if(q==2){
            int F;
            char C;
            scanf("%d %c",&F,&C);
            if((F==1 && !reverse) || (F==2 && reverse)){
                S[BUF-back]=C;
                back++;
            }
            else{
                S[BUF+length] = C;
                length++;
            }   
        }
    }
    if(!reverse){
        for(int i=BUF-back+1;i<BUF+length;i++)
         printf("%c",S[i]);
    }
    else{
        for(int i=BUF+length-1;i>BUF-back;i--)
            printf("%c",S[i]);
    }
}
