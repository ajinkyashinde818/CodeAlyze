#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))


int bisect_left(long long x,long long  a[],int left,int right){
   int mid;
   right++;
   while (left < right) {
      mid = (left + right) / 2;
      if (a[mid] < x) {
         left = mid + 1;
      } else {
         right = mid;
      }
   }
   return left;
}

int main(void) {
   int A,B,Q;
   scanf("%d%d%d", &A,&B,&Q);
   long long *shrine = (long long *)calloc((A+3) , sizeof(long long));
   long long *temple = (long long *)calloc((B+3) , sizeof(long long));
   shrine[0] = -100000000000000LL;
   temple[0] = -100000000000000LL;
   for (int i = 1; i <= A; i++) {
      scanf("%lld", &shrine[i]);
   }
   for (int i = 1; i <= B; i++) {
      scanf("%lld", &temple[i]);
   }
   shrine[A+1] = 100000000000000LL;
   temple[B+1] = 100000000000000LL;
   for (int i = 0; i < Q; i++) {
      long long now;
      scanf("%lld", &now);
      int s1 = bisect_left(now,shrine,0,A+1)-1;
      int s2 = bisect_left(now,shrine,0,A+1);
      int t1 = bisect_left(now,temple,0,B+1)-1;
      int t2 = bisect_left(now,temple,0,B+1);
      long long ans = 10000000000000LL;
      ans = MIN(ans,ABS(shrine[s1]-now) + ABS(shrine[s1]-temple[t1]));
      ans = MIN(ans,ABS(shrine[s1]-now) + ABS(shrine[s1]-temple[t2]));
      ans = MIN(ans,ABS(shrine[s2]-now) + ABS(shrine[s2]-temple[t1]));
      ans = MIN(ans,ABS(shrine[s2]-now) + ABS(shrine[s2]-temple[t2]));
      ans = MIN(ans,ABS(temple[t1]-now) + ABS(shrine[s1]-temple[t1]));
      ans = MIN(ans,ABS(temple[t1]-now) + ABS(shrine[s2]-temple[t1]));
      ans = MIN(ans,ABS(temple[t2]-now) + ABS(shrine[s1]-temple[t2]));
      ans = MIN(ans,ABS(temple[t2]-now) + ABS(shrine[s2]-temple[t2]));
      printf("%lld\n",ans);
   }
   return 0;
}
