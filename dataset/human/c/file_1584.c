#include <stdio.h>
int main(){
    char a[300000];
    int now=0,r=1,ans=0;
    for(int i=0;i<300000;i++)a[i]='\0';
    scanf("%s",a);
    while(a[now]!='\0')now++;
    for(int i=0;i<now-r;i++){
        if(a[i]!=a[now-r]){
            if(a[now-r]=='x'){
                r++;
                i--;
            }
            else if(a[i]!='x'){
                printf("-1\n");
                return 0;
            }
            ans++;
        }
        else r++;
    }
    printf("%d\n",ans);
}
