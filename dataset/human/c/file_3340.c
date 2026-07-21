#include <stdio.h>
#include <string.h>

int main(void){
    int a, i;
    char S[100005];
    scanf("%s", S);
    i=strlen(S)-1;
    while (i!=-1) {
        a=1;
        if (S[i-4]=='d' && S[i-3]=='r' && S[i-2]=='e' && S[i-1]=='a' && S[i]=='m') {
            i-=5;
            a=0;
            // printf("%d\n", i);
        }
        if (a==0) continue;
        if (S[i-4]=='e' && S[i-3]=='r' && S[i-2]=='a' && S[i-1]=='s' && S[i]=='e') {
            i-=5;
            a=0;
            // printf("%d\n", i);
        }
        if (a==0) continue;
        if (S[i-5]=='e' && S[i-4]=='r' && S[i-3]=='a' && S[i-2]=='s' && S[i-1]=='e' && S[i]=='r') {
            i-=6;
            a=0;
            // printf("%d\n", i);
        }
        if (a==0) continue;
        if (S[i-6]=='d' && S[i-5]=='r' && S[i-4]=='e' && S[i-3]=='a' && S[i-2]=='m' && S[i-1]=='e' && S[i]=='r') {
            i-=7;
            a=0;
            // printf("%d\n", i);
        }
        if (a==1) break;
    }
    if (i==-1) printf("YES");
    else printf("NO");
    // printf("%c", S[10]);
    return 0;
}
