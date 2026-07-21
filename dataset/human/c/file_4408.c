#include <stdio.h>

int main(void) {
int S[100][2];
int n,i,cnt;
cnt=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &S[i][0], &S[i][1]);

    for(i=0; i<n; i++){
        if(S[i][0]==S[i][1]) cnt++; 
        else                 cnt=0;
        if(cnt==3)          break;
    }
    if(cnt==3) printf("Yes");
    else       printf("No");    
    return 0;
}
