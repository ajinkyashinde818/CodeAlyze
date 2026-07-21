// https://atcoder.jp/contests/abc129/tasks/abc129_c

#include <stdio.h>
#define FOR(i,L,R) for (int i = L; i < R; i++)
#define MOD 1000000007
#define wez(n) int (n); scanf("%d",&(n))

int main(){
    wez(n);
    wez(m);
    int arr[100000];
    // initiate every step to value -1
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    
    // if the step is broke, change every value to 0
    FOR(i, 0, m){
        wez(a);
        arr[a] = 0;
    }
    
    // set the foot of the stairs equal to 1, and if the first step isn't broken, set it equal to 1
    arr[0] = 1;
    if (arr[1] == -1)
        arr[1] = 1;
    
    /* basically, we go to every step that isn't broken. to find the amount of different ways to get to that step,
       you just add the number of different ways to get to the last two steps. */
    for (int i = 0; i <= n; i++){
        if (arr[i] == -1)
            arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
    }
    
    printf("%d\n", arr[n]);
}
