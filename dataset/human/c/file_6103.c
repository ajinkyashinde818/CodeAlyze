#include <stdio.h>
  

    int n, m;
    int ans = -1e9;
    int in[200000];

void maxSerch(int);


int main(void) {
  int i;
 
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
 
    m = in[0];
 
    for (i = 1; i < n; i++) {
      maxSerch(i);
    }
    printf("%d\n", ans);
 
    return 0;
    }

void maxSerch(int i){


        if (ans < (in[i] - m)) {
            ans = in[i] - m;
        }
 
        if (in[i] < m) {
            m = in[i];
        }
 
    }
