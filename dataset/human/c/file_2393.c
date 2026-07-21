#include <stdio.h>

int main(){
    char buf[100];
    scanf("%s",buf);
    int cnt[256]={};
    for(int i=0;buf[i];i++){
        cnt[(unsigned int)buf[i]]++;
    }
    if(cnt['a']==1 && cnt['b']==1 && cnt['c']==1)puts("Yes");
    else puts("No");
    return 0;
}
