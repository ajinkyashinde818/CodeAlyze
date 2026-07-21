#include <stdio.h>

int main(void) {

  long a,b,q;
  scanf("%ld %ld %ld", &a, &b, &q);
  long s[a],t[b],x[q];
  for (long i = 0; i < a; i++) {
    scanf("%ld", &s[i]);
  }
  for (long i = 0; i < b; i++) {
    scanf("%ld", &t[i]);
  }
  for (long i = 0; i < q; i++) {
    scanf("%ld", &x[i]);
  }
  long west_s,east_s,west_t,east_t;
  long start,end,center;
  long move,min,max,ans;
  for (long i = 0; i < q; i++) {
    if (x[i] < s[0]) {
      west_s = -1;
      east_s = s[0];
    } else if (x[i] > s[a-1]) {
      west_s = s[a-1];
      east_s = -1;
    } else {
      start = 0;
      end = a-1;
      while (start+1 != end) {
        center = (start+end)/2;
        if (s[center] < x[i]) {
          start = center;
        } else {
          end = center;
        }
      }
      west_s = s[start];
      east_s = s[end];
    }
    if (x[i] < t[0]) {
      west_t = -1;
      east_t = t[0];
    } else if (x[i] > t[b-1]) {
      west_t = t[b-1];
      east_t = -1;
    } else {
      start = 0;
      end = b-1;
      while (start+1 != end) {
        center = (start+end)/2;
        if (t[center] < x[i]) {
          start = center;
        } else {
          end = center;
        }
      }
      west_t = t[start];
      east_t = t[end];
    }
    ans = -1;
    if (west_s != -1 && east_t != -1) {
      min = x[i]-west_s;
      if (east_t-x[i] < min) {
        min = east_t-x[i];
      }
      ans = east_t-west_s+min;
    }
    if (east_s != -1 && west_t != -1) {
      min = east_s-x[i];
      if (x[i]-west_t < min) {
        min = x[i]-west_t;
      }
      move = east_s-west_t+min;
      if (ans == -1 || move < ans) {
        ans = move;
      }
    }
    if (west_s != -1 && west_t != -1) {
      max = west_s;
      if (west_t < max) {
        max = west_t;
      }
      move = x[i]-max;
      if (ans == -1 || move < ans) {
        ans = move;
      }
    }
    if (east_s != -1 && east_t != -1) {
      max = east_s;
      if (east_t > max) {
        max = east_t;
      }
      move = max-x[i];
      if (ans == -1 || move < ans) {
        ans = move;
      }
    }
    printf("%ld\n", ans);
  }

  return 0;
}
