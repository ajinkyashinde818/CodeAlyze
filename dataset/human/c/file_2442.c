// abc of ABC
#include <stdio.h>

int main(void){
    char s[3+1];
    scanf("%s", s);

    int abcnum[3] = {};
    int able = 1;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a') abcnum[0]++;
        else if(s[i] == 'b') abcnum[1]++;
        else abcnum[2]++;

        if(abcnum[0] > 1 || abcnum[1] > 1 || abcnum[2] > 1){
            able = 0;
            break;
        }
    }

    printf("%s\n", (able)? "Yes" : "No");
    return 0;
}
