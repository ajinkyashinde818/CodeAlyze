#include <stdio.h>
#include <stdlib.h>
#define abs(x) ((x) > 0 ? (x) : -(x))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define shrine 1
#define temple -1
#define position 0

struct qwe {
  int id, spt, ns[2], nt[2];
  long long x;
};

int qwe_asc(const void *a, const void *b){
  struct qwe *A = (struct qwe *)a, *B = (struct qwe *)b;
  if(A->x > B->x) return  1;
  if(A->x < B->x) return -1;
  return 0;
}

int
main(int argc, char *argv[])
{
  int a, b, q;
  scanf("%d%d%d", &a, &b, &q);
  struct qwe *r;
  r = malloc(sizeof(struct qwe) * (a + b + q));
  int c = 1;
  while(c <= a){
    scanf("%lld", &r[c].x);
    r[c].id = c;
    r[c].spt = shrine;
    c++;
  }
  while(c <= a + b){
    scanf("%lld", &r[c].x);
    r[c].id = c;
    r[c].spt = temple;
    c++;
  }
  while(c <= a + b + q){
    scanf("%lld", &r[c].x);
    r[c].id = c;
    r[c].spt = position;
    c++;
  }
  

  r[0].x = -100000000000000; r[0].spt = 100;
  r[a + b + q + 1].x = 100000000000000; r[a + b + q + 1].spt = 100;

  qsort(r, c, sizeof(struct qwe), qwe_asc);

 

  int s = 0, t = 0;
  for(int i = 1; i <= c; i++){
    if(r[i].spt == shrine) s = i;
    if(r[i].spt == temple) t = i;
    r[i].ns[0] = s; r[i].nt[0] = t;
  }
  
  s = a + b + q + 1; t = a + b + q + 1; int p[100000], f = 0;
  for(int i = a + b + q; i >= 1; i--){
    if(r[i].spt == shrine) s = i;
    if(r[i].spt == temple) t = i;
    r[i].ns[1] = s; r[i].nt[1] = t;

    if(r[i].spt == position){
      p[f++] = i;
    }
  }
 

  int k; long long temp[4]; long long ans[100000]; long long Min;
  for(int i = 0; i < f; i++){
    k = p[i];
    temp[0] = max(r[k].x - r[r[k].ns[0]].x, r[k].x - r[r[k].nt[0]].x);
    temp[1] = min(2 * r[r[k].nt[1]].x - r[r[k].ns[0]].x - r[k].x,
		  2 * r[r[k].ns[1]].x - r[r[k].nt[0]].x - r[k].x);
    temp[2] = min(r[r[k].nt[1]].x - 2 * r[r[k].ns[0]].x + r[k].x,
		  r[r[k].ns[1]].x - 2 * r[r[k].nt[0]].x + r[k].x);
    temp[3] = max(r[r[k].nt[1]].x, r[r[k].ns[1]].x) - r[k].x;
    Min = 1000000000000000;
    for(int i = 0; i < 4; i++){
     
      Min = min(Min, temp[i]);
    }
    
    ans[r[k].id - a - b - 1] = Min;
  }

  for(int i = 0; i < q; i++) printf("%lld\n", ans[i]);

  return 0;
}
