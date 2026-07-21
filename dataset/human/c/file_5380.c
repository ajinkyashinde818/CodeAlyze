#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define REP(i,n) for(i=0;i<n;i++)

#define MAX 1000000
#define MOD 1000000007

long long fac[MAX], finv[MAX], inv[MAX];

//prototype declaration
int i_in();
long long ll_in();
double d_in();
char c_in();
void s_in(char *s);
void i_out(int i);
void ll_out(long long i);
void d_out(double i);
void c_out(char c);
void s_out(char *s);
int gcd(int a, int b);
int lcm(int a, int b);
long long ll_gcd(long long a, long long b);
long long ll_lcm(long long a, long long b);
void sort_asc(int *a);
void sort_desc(int *a);
int asc(const void *a, const void *b);
int desc(const void *a, const void *b);
void ll_sort_asc(long long *a);
void ll_sort_desc(long long *a);
int ll_asc(const void *a, const void *b);
int ll_desc(const void *a, const void *b);
double to_deg(double rad);
double distance(int xi, int yi, int xj, int yj);
void initComb();
long long comb(int n, int k);

//main function
int main() {
    int n = i_in(), m = i_in(), x = i_in(), i, j, min = MOD, flag = 1, z;
    int a[n][m], at[m], c[n], ct = 0;
    REP(i,m) at[i] = 0;
    REP(i,n) {
        c[i] = i_in();
        ct += c[i];
        REP(j,m) {
            a[i][j] = i_in();
            at[j] += a[i][j];
        }
    }
    REP(i,m) {
        if (at[i] < x) {
            i_out(-1);
            return 0;
        }
    }

    min = ct;
    REP(i,n) {
        flag = 1;
        REP(z,m) if (at[z] - a[i][z] < x) flag = 0;
        if (flag == 0) continue;
        if (min > ct - c[i]) min = ct - c[i];
        for (j = i + 1; j < n; j++) {
            flag = 1;
            REP(z,m) if (at[z] - a[i][z] - a[j][z] < x) flag = 0;
            if (flag == 0) continue;
            if (min > ct - c[i] - c[j]) min = ct - c[i] - c[j];
            for (int k = j + 1; k < n; k++) {
                flag = 1;
                REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] < x) flag = 0;
                if (flag == 0) continue;
                if (min > ct - c[i] - c[j] - c[k]) min = ct - c[i] - c[j] - c[k];
                for (int l = k + 1; l < n; l++) {
                    flag = 1;
                    REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] < x) flag = 0;
                    if (flag == 0) continue;
                    if (min > ct - c[i] - c[j] - c[k] - c[l]) min = ct - c[i] - c[j] - c[k] - c[l];
                    for (int o = l + 1; o < n; o++) {
                        flag = 1;
                        REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] < x) flag = 0;
                        if (flag == 0) continue;
                        if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o];
                        for (int p = o + 1; p < n; p++) {
                            flag = 1;
                            REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] < x) flag = 0;
                            if (flag == 0) continue;
                            if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p];
                            for (int q = p + 1; q < n; q++) {
                                flag = 1;
                                REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] - a[q][z] < x) flag = 0;
                                if (flag == 0) continue;
                                if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q];
                                for (int r = q + 1; r < n; r++) {
                                    flag = 1;
                                    REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] - a[q][z] - a[r][z] < x) flag = 0;
                                    if (flag == 0) continue;
                                    if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r];
                                    for (int s = r + 1; s < n; s++) {
                                        flag = 1;
                                        REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] - a[q][z] - a[r][z] - a[s][z] < x) flag = 0;
                                        if (flag == 0) continue;
                                        if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s];
                                        for (int t = s + 1; t < n; t++) {
                                            flag = 1;
                                            REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] - a[q][z] - a[r][z] - a[s][z] - a[t][z] < x) flag = 0;
                                            if (flag == 0) continue;
                                            if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s] - c[t]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s] - c[t];
                                            for (int u = t + 1; u < n; u++) {
                                                flag = 1;
                                                REP(z,m) if (at[z] - a[i][z] - a[j][z] - a[k][z] - a[l][z] - a[o][z] - a[p][z] - a[q][z] - a[r][z] - a[s][z] - a[t][z] - a[u][z] < x) flag = 0;
                                                if (flag == 0) continue;
                                                if (min > ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s] - c[t] - c[u]) min = ct - c[i] - c[j] - c[k] - c[l] - c[o] - c[p] - c[q] - c[r] - c[s] - c[t] - c[u];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    i_out(min);

    return 0;
}

//body function
int i_in() {
    int i;
    scanf("%d", &i);
    return i;
}

long long ll_in() {
    long long i;
    scanf("%lld", &i);
    return i;
}

double d_in() {
    double i;
    scanf("%lf", &i);
    return i;
}

char c_in() {
    char c;
    scanf("%c", &c);
    return c;
}

void s_in(char *s) {
    scanf("%s", s);
}

void i_out(int i) {
    printf("%d\n", i);
}

void ll_out(long long i) {
    printf("%lld\n", i);
}

void d_out(double i) {
    printf("%lf\n", i);
}

void c_out(char c) {
    printf("%c\n", c);
}

void s_out(char *s) {
    printf("%s\n", s);
}

/*
    int型の最大公約数
*/

int gcd(int a, int b) {
    int r;

    if (a < b) {
        r = a;
        a = b;
        b = r;
    }

    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

/*
    int型の最小公倍数
*/

int lcm(int a, int b) {
    int r = ll_gcd(a, b);
    a /= r;
    return a * b;
}

/*
    long long型の最大公約数
*/

long long ll_gcd(long long a, long long b) {
    long long r;

    if (a < b) {
        r = a;
        a = b;
        b = r;
    }

    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

/*
    long long型の最小公倍数
*/

long long ll_lcm(long long a, long long b) {
    long long r = ll_gcd(a, b);
    a /= r;
    return a * b;
}

/*
    int型の昇順ソート
*/

void sort_asc(int *a) {
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), asc);
}

/*
    int型の降順ソート
*/

void sort_desc(int *a) {
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), desc);
}

/*
    int型の昇順用比較関数
*/

int asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/*
    int型の降順用比較関数
*/

int desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

/*
    long long型の昇順ソート
*/

void ll_sort_asc(long long *a) {
    qsort(a, sizeof(a)/sizeof(long long), sizeof(long long), ll_asc);
}

/*
    long long型の降順ソート
*/

void ll_sort_desc(long long *a) {
    qsort(a, sizeof(a)/sizeof(long long), sizeof(long long), ll_desc);
}

/*
    long long型の昇順用比較関数
*/

int ll_asc(const void *a, const void *b) {
    long long *A = (long long *)a;
    long long *B = (long long *)b;
    if (*A > *B) return 1;
    else if (*A < *B) return -1;
    else return 0;
}

/*
    long long型の降順用比較関数
*/

int ll_desc(const void *a, const void *b) {
    long long *A = (long long *)a;
    long long *B = (long long *)b;
    if (*A < *B) return 1;
    else if (*A > *B) return -1;
    else return 0;
}

/*
    弧度法を度数法に
*/

double to_deg(double rad) {
    return rad * 180.0 / (atan(1.0) * 4.0);
}

/*
    二点間の距離
*/

double distance(int xi, int yi, int xj, int yj) {
    return hypot(xj - xi, yj - yi);
}

/*
    組み合わせ用配列の初期化
*/

void initComb() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

/*
    nCkの組み合わせ計算
*/

long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
