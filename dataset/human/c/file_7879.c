#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define XMAX 1000000000

int main(){
  int n, i, j, k, x, q;
  char buf[32];
  unsigned int *a;
  a = (unsigned int *)malloc(XMAX/8);
  for (i=0; i<XMAX/8/sizeof(int); i++)
    a[i] = 0;
  
  int count=0;
  unsigned int bit[32];
  unsigned int u = 1;
  for (i=0; i<32; i++) {
    bit[i] = u;
    u *= 2;
  }
  
  fgets(buf, 32, stdin);
  n = atoi(buf);
  for (i = 0; i < n; i++){
    fgets(buf, 32, stdin);
    q = atoi(buf);
    x = atoi(strchr(buf, ' '));
    
    if (q==0) {
      if ((a[x/32] & bit[x%32]) == 0) {
	a[x/32] |= bit[x%32];
	count++;
      }
      
      k = count;
      if (k==0) {
	putc_unlocked('0', stdout);
      } else {
	if (k<0) {
	  putc_unlocked('-', stdout);
	  k=-k;
	}
	for (j=1; j*10<=k; j*=10);
	for (;j>0; j/=10) {
	  putc_unlocked('0'+k/j, stdout);
	  k %= j;
	}
      }
      putc_unlocked('\n', stdout);
      
    } else if (q==1){
      if ((a[x/32] & bit[x%32]) == 0)
	putc_unlocked('0', stdout);
      else
	putc_unlocked('1', stdout);
      putc_unlocked('\n', stdout);
    } else { // q==2
      if (a[x/32] & bit[x%32]) {
	count--;
	a[x/32] &= ~bit[x%32];
      }

    }
  }
  return 0;
}
