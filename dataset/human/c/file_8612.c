#include <stdio.h>
     
    int a[100001];
     
    int main()
    {
      int N;
      int bt = 1;
      scanf("%d", &N);
      for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
      }
      int i = 0;
      while((bt != 2) && (i < N)){
        bt = a[bt];
        i++;
      }
      if(bt == 2) printf("%d\n", i);
      else        printf("%d\n", -1);
      return 0;
    }
