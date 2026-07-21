#include <stdio.h>
#include <string.h>
void rev(char* s) {
    int i, l = strlen(s);
    for (i = 0; i < l / 2; i++) {
        char t = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = t;
    }
 
 
}
int main(void) {
    char T[4][8]={"dream","dreamer","erase","eraser"};
    char buf[100001];
    int i;
    int k, c = 0;
 
    scanf("%s",buf);
    rev(buf);
  
    for (i = 0; i < 4; i++)
        rev(T[i]);
  
    int l=strlen(buf);
while(c<l){
  k=-1;
    for (i = 0; i < 4; i++) {
        if (!strncmp(buf + c, T[i], strlen(T[i]))) {
            k = strlen(T[i]);
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
