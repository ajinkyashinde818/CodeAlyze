#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}
int compare_int2(const void *a, const void *b)
{
    return *(char*)b - *(char*)a;
}

int main()
{
    char s[100]={};
    char t[100]={};
    scanf("%s", s);
    scanf("%s", t);
    qsort(s,100,sizeof(char),compare_int);
    qsort(t,100,sizeof(char),compare_int2);
    int n=0,m=0;
    while(s[n]==0){n++;}
    while(t[m]==0){m++;}
    for(int i=0;i<100-n;i++){
        s[i]=s[i+n];
        if(n!=0)
        s[i+n]=0;
    }
    for(int i=0;i<100-m;i++){
        t[i]=t[i+m];
        if(m!=0)
        t[i+m]=0;
    }
    int flag=0;
    for(int i=0;i<100;i++){
        if(s[i]==t[i]){
            if(s[i]==0)
                break;
            continue;
        }
        if(s[i]<t[i]){
            flag=1;
            break;
        }
        if(t[i]<s[i]){
            flag=0;
            break;
        }
    }
    printf("%s\n",(flag==1)?"Yes":"No");
    
    return 0;
}
