#include <stdio.h>
#include <string.h>
int main(void){
    char s[1000], t[1000];
    int n, m, i, j, p, q;
    
    scanf("%s%s",s,t);
    n=strlen(s);
    m=strlen(t);
    
    for(i=0;i<n;i++){
        p=s[i];
        for(j=i;j<n;j++){
            if(s[j]<p){
                p=s[j];
                s[j]=s[i];
                s[i]=p;
            }
        }
    }
    for(i=0;i<m;i++){
        p=t[i];
        for(j=i;j<m;j++){
            if(t[j]>p){
                p=t[j];
                t[j]=t[i];
                t[i]=p;
            }
        }
    }
    
    if(n<m) q=n;
    else    q=m;
    for(i=0;i<q;i++){
        if(s[i]<t[i]){
            printf("Yes\n");
            return 0;
        }
        else if(s[i]>t[i]){
            printf("No\n");
            return 0;
        }
    }
    if(n<m) printf("Yes\n");
    else    printf("No\n");
    return 0;
}
