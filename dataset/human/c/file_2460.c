#include <stdio.h>
int main(){
    char s[4];
    scanf("%s",s);
    int l[3]={0};
    for(int i=0;i<3;i++){
        l[s[i]-'a']++;
    }
    printf("%s\n",(l[0]==1 && l[1]==1 && l[2]==1)?"Yes":"No");
    return 0;
}
