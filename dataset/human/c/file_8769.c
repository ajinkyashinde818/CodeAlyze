#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpnum(const void * n1, const void * n2) {
	if (*(long *)n1 > *(long *)n2) {
		return -1;
	}
	else if (*(long *)n1 < *(long *)n2) {
		return 1;
	}
	else {
		return 0;
	}
}

int cmpnum2(const void * n1, const void * n2) {
	if (labs(*(long *)n1) > labs(*(long *)n2)) {
		return 1;
	}
	else if (labs(*(long *)n1) < labs(*(long *)n2)) {
		return -1;
	}
	else {
		return 0;
	}
}

int main(void) {

  long n,k;
  scanf("%ld %ld", &n, &k);
  long a[n];
  long plus = 0, zero = 0, minus = 0;
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    if (a[i] > 0) {
      plus++;
    } else if (a[i] == 0) {
      zero++;
    } else {
      minus++;
    }
  }
  qsort(a, n, sizeof(long), cmpnum);
  long mod = pow(10,9)+7;
  int flag = 0;
  long pairs = minus/2;
  if (k/2 < pairs) {
    pairs = k/2;
  }
  if (plus+pairs*2 >= k) {
    flag = 1;
  } else if (zero == 0) {
    flag = -1;
  }
  long ans;
  long p_cur,m_cur,left,p_left,m_left;
  long tmp1,tmp2;
  if (flag == 1) {
    ans = 1;
    p_cur = 0;
    m_cur = n-1;
    left = k;
    p_left = plus;
    m_left = minus/2*2;
    if (k%2 == 1) {
      ans = a[0];
      p_cur++;
      left--;
      p_left--;
    }
    while (left > 0) {
      if (p_left == 0) {
        ans *= -a[m_cur];
        ans %= mod;
        ans *= -a[m_cur-1];
        ans %= mod;
        left -= 2;
        m_cur -= 2;
      } else if (m_left == 0) {
        ans *= a[p_cur];
        ans %= mod;
        ans *= a[p_cur+1];
        ans %= mod;
        left -= 2;
        p_cur += 2;
      } else {
        tmp1 = a[p_cur]*a[p_cur+1];
        tmp2 = (-a[m_cur])*(-a[m_cur-1]);
        if (tmp1 >= tmp2) {
          ans *= a[p_cur];
          ans %= mod;
          ans *= a[p_cur+1];
          ans %= mod;
          left -= 2;
          p_cur += 2;
        } else {
          ans *= -a[m_cur];
          ans %= mod;
          ans *= -a[m_cur-1];
          ans %= mod;
          left -= 2;
          m_cur -= 2;
        }
      }
    }
    printf("%ld\n", ans);
  } else if (flag == -1) {
    qsort(a, n, sizeof(long), cmpnum2);
    ans = 1;
    for (long i = 0; i < k; i++) {
      ans *= (mod+a[i]);
      ans %= mod;
    }
    printf("%ld\n", ans);
  } else {
    printf("0\n");
  }

  return 0;
}
