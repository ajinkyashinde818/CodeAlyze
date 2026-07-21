#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int uint64;
typedef long long int          int64;
 
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void get_N (int64 *n)
{
  int cnt;
  
  cnt = scanf("%lld", n);

  return;
}

void get_NK (int64 *n, int64 *k)
{
  int cnt;

  cnt = scanf("%lld %lld", n, k);

  return;
}

void get_N1234 (int64 *n1, int64 *n2, int64 *n3, int64 *n4)
{
  int cnt;

  if (n2 == NULL) {
    cnt = scanf("%lld", n1);
    return;
  }
  if (n3 == NULL) {
    cnt = scanf("%lld %lld", n1, n2);
    return;
  }
  if (n4 == NULL) {
    cnt = scanf("%lld %lld %lld", n1, n2, n3);
    return;
  }
  cnt = scanf("%lld %lld %lld %lld", n1, n2, n3, n4);
  return;
}

void omit_LF (void)
{
  char c;
  int  cnt;
  
  cnt = scanf("%c", &c);
  return;
}

char *get_S (int64 n)
{
  char *buf;
  int  i;
  int  cnt;

  buf = (char *)malloc((size_t)(n * sizeof(char)));
  if (buf == NULL) {
    return NULL;
  }

  cnt = scanf("%s", buf);

  return buf;
}

char *get_SN (int64 max, int64 *size)
{
  char *buf;
  int  i;
  int  n;
  int  cnt;

  buf = (char *)malloc((size_t)(max * sizeof(char)));
  if (buf == NULL) {
    return NULL;
  }

  cnt = scanf("%s", buf);

  n = strlen(buf);

  *size = n;
  
  return buf;
}

int64 *get_NSeq (int64 n)
{
  int64 *buf;
  int64 i;

  buf = (int64 *)malloc((size_t)(n * sizeof(int64)));
  for (i=0; i<n; i++) {
    get_N(&buf[i]);
  }

  return buf;
}


/*
  bitmap
 */
typedef struct _tmp_bitmap_t {
  uint64 bitlen;
  uint64 arraylen;
  uint64 *map;
} tmp_bitmap_t;

tmp_bitmap_t *bitmap_create_map (uint64 bitlen)
{
  tmp_bitmap_t *m;

  m = (tmp_bitmap_t *)malloc(sizeof(tmp_bitmap_t));
  memset(m, 0, sizeof(tmp_bitmap_t));

  m->arraylen = (bitlen / 64) + 1;

  m->bitlen = bitlen;
  m->map = (uint64 *)malloc(sizeof(uint64) * m->arraylen);
  memset (m->map, 0, sizeof(uint64) * m->arraylen);

  return m;
}

void bitmap_set_bit (tmp_bitmap_t *m, uint64 bit)
{
  m->map[(bit/64)] |= (1 << (bit%64));

  return;
}

void bitmap_clr_bit (tmp_bitmap_t *m, uint64 bit)
{
  m->map[(bit/64)] &= ~(1 << (bit%64));

  return;
}

uint64 bitmap_get_bit (tmp_bitmap_t *m, uint64 bit)
{
  if (m->map[(bit/64)] & (1 << (bit%64))) {
    return 1;
  }
  return 0;
}

/*
  string map

  ex.
  0123456
0 #.###.# <= y=0, x=0..6
1 #####.#
2 ##....#
3 ##.#### <= y=3, x=0..6
 */

#define STRMAP_CHAR_ZERO '.'
#define STRMAP_CHAR_ONE  '#'

typedef struct _tmp_strmap_t {
  uint64 lenx;
  uint64 leny;
  tmp_bitmap_t *bitmap;
} tmp_strmap_t;

tmp_strmap_t *strmap_create_map (uint64 lenx, uint64 leny)
{
  tmp_strmap_t *sm;
  
  sm = (tmp_strmap_t *)malloc(sizeof(tmp_strmap_t));
  memset(sm, 0, sizeof(tmp_strmap_t));

  sm->lenx = lenx;
  sm->leny = leny;

  sm->bitmap = bitmap_create_map (lenx*leny);

  return sm;
}

/* return bit position for x,y*/
uint64 strmap_xy2bit (tmp_strmap_t *sm, uint64 x, uint64 y)
{
  uint64 bit = 0;

  bit = y*sm->lenx;
  bit += x;

  return bit;
}

/* 
void strmap_set_one (tmp_strmap_t *sm, uint64 x, uint64 y)
{
  
}

void strmap_input_map (uint64 lenx, uint64 leny)
{


}
*/

/*
sortable data
 */
typedef struct _tmp_t {
  int64    a;
  int64    b;
} tmp_t;

typedef int64 simple_t;

int compare_simple(const void *a, const void *b)
{
  simple_t *x;
  simple_t *y;

  x = (simple_t *)a;
  y = (simple_t *)b;

  if (x > y) return 1;
  if (y < x) return -1;

  return 0;
}
void qsort_simple (simple_t *array, int size)
{
  qsort(array, size, sizeof(simple_t), compare_simple);
}

int compare_a(const void *a, const void *b)
{
  tmp_t *x;
  tmp_t *y;

  x = (tmp_t *)a;
  y = (tmp_t *)b;

  if (x->a > y->a) return 1;
  if (x->a < y->a) return -1;

  return 0;
}

int compare_b(const void *a, const void *b)
{
  tmp_t *x;
  tmp_t *y;

  x = (tmp_t *)a;
  y = (tmp_t *)b;

  if (x->b > y->b) return 1;
  if (x->b < y->b) return -1;

  return 0;
}

void qsort_a (tmp_t *array, int size)
{
  qsort(array, size, sizeof(tmp_t), compare_a);
}

void qsort_b (tmp_t *array, int size)
{
  qsort(array, size, sizeof(tmp_t), compare_b);
}


int resolve1()
{
  int64 R;
  double pi=3.14159;
  double L;

  get_N(&R);

  L = pi*R*2;

  printf("%lf", L);
  return 0;
}

int resolve2()
{
  int64 N,M;
  int64 *A;
  int64 i;
  int64 total = 0;
  int64 play=0;
  
  get_NK(&N, &M);
  A = get_NSeq(M);

  for (i=0; i < M; i++) {
    total += A[i];
  }

  if (N >= total) {
    play = N - total;
  } else {
    printf("-1");
    return 0;
  }

  printf("%lld",play);
  return 0;
}


void resolve3()
{
  int64 N = 0;
  int64 i, d1, d2;
  int64 match_cnt = 0;
  
  
  get_N(&N);

  for (i=0; i<N; i++) {
    get_NK(&d1,&d2);
    if (d1 == d2) {
      match_cnt++;
      if (match_cnt == 3) {
        printf("Yes");
        return;
      }
    } else {
      match_cnt = 0;
    }
  }

  printf("No");

  return;
}

int main()
{
  resolve3();

  return 0;
}
