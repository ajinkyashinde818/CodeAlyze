#include <stdio.h>

int main(void) {
    int s[3]={0};
    char ss[4];
    scanf("%s", ss);
    s[ss[0]-'a']++;
    s[ss[1]-'a']++;
    s[ss[2]-'a']++;
    
    if(s[0]==1 && s[1]==1 && s[2]==1) printf("Yes");
    else printf("No");
    
    return 0;
}
