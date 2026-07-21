#include <stdio.h>
#include <string.h>
int main()
{   char s[100001];
    scanf("%s",s);
    int n=strlen(s),ans=0,l=0,r=n-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
            continue;
            }
        if(s[r]=='x'){
            r--;
            ans++;
            continue;
        }
        if(s[l]=='x'){
            l++;
            ans++;
            continue;
        }
        if(s[l]!=s[r]){
            printf("-1");
            return 0;
        }
    }
    printf("%d",ans);
    return 0;
}
