#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s2[100001];
    scanf("%s",s2);
    int s2len=strlen(s2);
    int q;
    scanf("%d",&q);
    char *s1,*s3;
    s1=(char*)malloc(sizeof(char)*(q+1));
    s3=(char*)malloc(sizeof(char)*(q+1));
    int s1len=0;
    int s3len=0;
    int t,f;
    char c;
    int reverse=1;
    for (int i = 0; i < q; i++)
    {
        scanf("%d",&t);
        if(t==1) reverse*=-1;
        else{
            scanf("%d %c",&f,&c);
            if (reverse==1)
            {
                if (f==1)
                {
                    s1[s1len]=c;
                    s1len++;
                }else if(f==2){
                    s3[s3len]=c;
                    s3len++;
                }
            }else if(reverse==-1){
                if (f==2)
                {
                    s1[s1len]=c;
                    s1len++;
                }else if(f==1){
                    s3[s3len]=c;
                    s3len++;
                }
            }
        }
        
    }
    if (reverse==1)
    {
        for (int i = 0; i < s1len; i++)
        {
            printf("%c",s1[s1len-1-i]);
        }
        printf("%s",s2);
        for (int i = 0; i < s3len; i++)
        {
            printf("%c",s3[i]);
        }        
    }else if (reverse==-1){
        for (int i = 0; i < s3len; i++)
        {
            printf("%c",s3[s3len-1-i]);
        }
        for (int i = 0; i < s2len; i++)
        {
            printf("%c",s2[s2len-1-i]);
        }
        for (int i = 0; i < s1len; i++)
        {
            printf("%c",s1[i]);
        }        

    }
    return 0;
}
