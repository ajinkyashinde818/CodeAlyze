#include <stdio.h>
int main(){
    int n,s[1000],temp;
    scanf("%d",&n);
    for(int i=0;i<1000;i++)s[i]=0;
    while(n--){
        scanf("%d",&temp);
        s[temp]++;
    }
    for(int i=990;i>=0;i--){
        s[i]+=s[i+1];
        if(s[i]>=i){
            printf("%d\n",i);
            break;
        }
    }
}
