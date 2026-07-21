#include<stdio.h>
#include<string.h>
int i,l,p,ans,b[100010];
char s[100010],a[100010];
int abs(int a){
    if(a<0) return -a; else return a;
}
int main(){
    scanf("%s",s);
    for(i=0;s[i];i++) if(s[i]!='x') a[l++]=s[i]; else b[l]++;
    a[l]='\0';
    p=1;
    for(i=0;i<l/2;i++) if(a[i]!=a[l-1-i]) p=0;
    if(p){
        for(i=0;i<(l+1)/2;i++) ans+=abs(b[i]-b[l-i]);
        printf("%d\n",ans);
    }else printf("-1\n");
}
