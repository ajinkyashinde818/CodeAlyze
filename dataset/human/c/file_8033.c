#include <stdio.h>
#include <stdlib.h>

int main(void) {

  long h,w,ch,cw,dh,dw;
  scanf("%ld %ld\n%ld %ld\n%ld %ld", &h, &w, &ch, &cw, &dh, &dw);
  char **s;
  long **warp;
  s = (char **)malloc(sizeof (char*) * h);
  warp = (long **)malloc(sizeof (long*) * h);
  for (long i = 0; i < h; i++) {
  	s[i] = (char *)malloc(sizeof (char) * (w+1));
    warp[i] = (long *)malloc(sizeof (long) * w);
    scanf("%s", s[i]);
  }
  long **visited,size = h*w;
  visited = (long **)malloc(sizeof (long*) * size);
  for (long i = 0; i < size; i++) {
    visited[i] = (long *)malloc(sizeof (long) * 2);
  }
  long cur = 0,head,tail,start,end,sq_h,sq_w;
  for (long i = 0; i < h; i++) {
    for (long j = 0; j < w; j++) {
      warp[i][j] = -1;
      if (s[i][j] == '#') {
        visited[cur][0] = i;
        visited[cur][1] = j;
        cur++;
      }
    }
  }
  warp[ch-1][cw-1] = 0;
  visited[cur][0] = ch-1;
  visited[cur][1] = cw-1;
  head = cur;
  start = cur;
  end = cur;
  cur++;
  int flag;
  while (cur < size) {
    flag = 0;
    for (long i = start; i <= end; i++) {
      sq_h = visited[i][0];
      sq_w = visited[i][1];
      if (sq_h != 0 && s[sq_h-1][sq_w] == '.' && warp[sq_h-1][sq_w] == -1) {
        warp[sq_h-1][sq_w] = warp[sq_h][sq_w];
        visited[cur][0] = sq_h-1;
        visited[cur][1] = sq_w;
        cur++;
        flag = 1;
      }
      if (sq_h != h-1 && s[sq_h+1][sq_w] == '.' && warp[sq_h+1][sq_w] == -1) {
        warp[sq_h+1][sq_w] = warp[sq_h][sq_w];
        visited[cur][0] = sq_h+1;
        visited[cur][1] = sq_w;
        cur++;
        flag = 1;
      }
      if (sq_w != 0 && s[sq_h][sq_w-1] == '.' && warp[sq_h][sq_w-1] == -1) {
        warp[sq_h][sq_w-1] = warp[sq_h][sq_w];
        visited[cur][0] = sq_h;
        visited[cur][1] = sq_w-1;
        cur++;
        flag = 1;
      }
      if (sq_w != w-1 && s[sq_h][sq_w+1] == '.' && warp[sq_h][sq_w+1] == -1) {
        warp[sq_h][sq_w+1] = warp[sq_h][sq_w];
        visited[cur][0] = sq_h;
        visited[cur][1] = sq_w+1;
        cur++;
        flag = 1;
      }
    }
    if (flag == 1) {
      start = end+1;
      end = cur-1;
    } else {
      tail = cur-1;
      for (long i = head; i <= tail; i++) {
        sq_h = visited[i][0];
        sq_w = visited[i][1];
        for (long j = sq_h-2; j <= sq_h+2; j++) {
          for (long k = sq_w-2; k <= sq_w+2; k++) {
            if (j >= 0 && j < h && k >= 0 && k < w && s[j][k] == '.' && warp[j][k] == -1) {
              warp[j][k] = warp[sq_h][sq_w]+1;
              visited[cur][0] = j;
              visited[cur][1] = k;
              cur++;
              flag = 1;
            }
          }
        }
      }
      if (flag == 0) {
        break;
      }
      head = tail+1;
      start = head;
      end = cur-1;
    }
  }
  printf("%ld\n", warp[dh-1][dw-1]);

  return 0;
}
