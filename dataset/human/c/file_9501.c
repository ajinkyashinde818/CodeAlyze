#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

    int n, d, x, a;
    scanf("%d %d %d", &n, &d, &x);

    int mysum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int cnt = 1;
        while (1) {

            if (cnt * a + 1 <= d) {
                mysum += 1;
                cnt++;
                
            }else{
                break;
            }
        }
        mysum+=1;
    }
    printf("%d\n", mysum+x);

    


    return 0;
}
