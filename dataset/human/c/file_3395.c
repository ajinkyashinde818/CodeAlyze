#include <stdio.h>
#include <string.h>

void reverse(char *s){
    char t[100001];
    int length;
    int i;
    length = strlen(s);
    strcpy(t, s);
    for(i=0;i<length;i++){
        s[i] = t[length-1-i];
    }
}

int main()
{
    char s[100001];
    int i = 0;
    char a[4][8] = {"dream", "dreamer", "erase", "eraser"};
    
    scanf("%s", s);
    
    reverse(s);
    for(i=0;i<4;i++) reverse(a[i]);
    
    int c = 0, l = strlen(s);
    
    while(c<l){
        int k = -1;
        for(i=0;i<4;i++){
            if(!strncmp(s+c,a[i], strlen(a[i]))){
                k = strlen(a[i]);
                break;
            }
        }
        if(k<0){
            printf("NO");
            return 0;
        }
        c += k;
    }
    printf("YES");
    
    return 0;
}
