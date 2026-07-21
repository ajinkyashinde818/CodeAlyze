#include <stdio.h>
int main(void) {
    int N,M=1,count=0;
    scanf("%d", &N);
    int a[N];
  for(int i=0;i<N;i++)
    scanf("%d",&a[i]);
      while (1) {
        N=M-1;
        M = a[M-1];
        count++;
        if (M == 2) {
            printf("%d", count);
            return 0;
        }
        if(M==-1){
            printf("-1");
            return 0;
   		}
        a[N]=-1;
      }
    return 0;
}
