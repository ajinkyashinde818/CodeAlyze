#include<stdio.h>
#include<string.h>

int main() {
    int i, j;
    char S[100], a ,abc[] = "abc";
    
    scanf("%s", S);

    for(i=0; S[i]!=0; i++) {
        for(j=i+1; S[j]!=0; j++) {
            if(S[i] > S[j]) {
                a = S[i];
                S[i] = S[j];
                S[j] = a;
            }
        }
    }

    if(strcmp(S, abc) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
