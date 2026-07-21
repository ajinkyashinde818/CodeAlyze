#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  const i32 n = read_int();
  const i32 l = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i32 *deq = (i32 *) calloc (n, sizeof (i32));
  i32 front = 0;
  i32 last = 0;
  for (i32 i = 0; i < l; ++i) {
    while (front < last && a[i] < deq[last - 1]) last--;
    deq[last++] = a[i];
  }
  print_int (deq[front]);
  for (i32 i = l; i < n; ++i) {
    if (a[i - l] == deq[front]) front++;
    while (front < last && a[i] < deq[last - 1]) last--;
    deq[last++] = a[i];
    putchar (' ');
    print_int (deq[front]);
  }
  putchar('\n');
}

int main (void) {
  run ();
  return 0;
}
