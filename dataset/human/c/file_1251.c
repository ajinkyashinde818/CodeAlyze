#include<stdio.h>
#include<string.h>
int main(void)
{
    int i=0,j=0,k,tmp;
    char s[101],t[101];
    scanf("%s%s",s,t);
    while(s[i]!='\0'){
        k=i;
        while(s[k]!='\0'){
            if(s[i]>s[k]){
                tmp=s[i]; s[i]=s[k]; s[k]=tmp;
            }
            k++;
        }
        i++;
    }
    while(t[j]!='\0'){
        k=j;
        while(t[k]!='\0'){
            if(t[j]<t[k]){
                tmp=t[j]; t[j]=t[k]; t[k]=tmp;
            }
            k++;
        }
        j++;
    }
    if(strcmp(s,t)<0)
        printf("Yes\n");
    else 
        printf("No\n");
    return 0;
}
