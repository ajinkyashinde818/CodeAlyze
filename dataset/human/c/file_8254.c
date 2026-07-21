#include <stdio.h>

int main(void){
    // Your code here!
    char s[11],t;
    int N;
    int K;
    scanf("%d",&N);
    scanf("%s",s);
    scanf("%d",&K);
    t = s[K-1];
    for(int i = 0; i < N; i++)
    {
        if(s[i] != t)
        {
            s[i] = '*';
        }
    }
    printf("%s\n",s);
}
