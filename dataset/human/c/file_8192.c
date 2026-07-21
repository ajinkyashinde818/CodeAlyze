#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
typedef int keytype;

int gcd(int a, int b){ return (a % b) ? gcd(b, a % b) : b;}
int lcm(int a, int b){ return (a / gcd(a, b)) * b;}

void quicksort(keytype a[], int first, int last)
{
    int i, j;
    keytype x, t;

    x = a[(first + last) / 2];
    i = first;  j = last;
    for ( ; ; ) {
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i >= j) break;
        t = a[i];  a[i] = a[j];  a[j] = t;
        i++;  j--;
    }
    if (first  < i - 1) quicksort(a, first , i - 1);
    if (j + 1 < last) quicksort(a, j + 1, last);
}

int is_prime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int is_substr(char s[], char t[], int i){
    int flag = 1;

    if(s[i] == '\0') flag = 0;

    for(int j = 0; j < strlen(t); ++j, ++i){
        if(s[i] != t[j]){
            flag = 0;
            break;
        }
    }
    return flag;
}

// factor list, number of factors, natural number
void factorize(int ftr[], int *num, int n){
    int a = 2, cnt = 0;

    while(n >= a){
        if(n % a == 0){
            n = n / a;
            ftr[cnt++] = a;
        }else{
            a++;
        }
    }
    *num = cnt;
}

void comb(int size1, int size2, int v[size1][size2]){
  for(int i = 0; i < size1; i++){
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for(int k = 1; k < size1; k++){
    for(int j = 1; j < k; j++){
      v[k][j] = (v[k-1][j-1] + v[k-1][j]);
    }
  }
}

int abs_val(int a, int b){
    if(a > b) return a - b;
    else return b - a;
}

int main(){
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int ans1 = a * b;
    int ans2 = c * d;

    if(ans1 >= ans2) printf("%d\n", ans1);
    else printf("%d\n", ans2);

    return 0;
}
