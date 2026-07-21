#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define REP(i,n) for(i=0;i<n;i++)

//prototype declaration
int iin();
long long llin();
double din();
char cin();
void stin(char *s);
void iout(int i);
void llout(long long i);
void dout(double i);
void cout(char c);
void stout(char *s);
int gcd(int a, int b);
int lcm(int a, int b);
long long llgcd(long long a, long long b);
long long lllcm(long long a, long long b);
int asc(const void *a, const void *b);
int desc(const void *a, const void *b);

//main function
int main() {
    int a = iin(), b = iin(), c = iin(), d = iin();
    iout(a * b > c * d ? a * b : c * d);
    return 0;
}

//body function
int iin() {
    int i;
    scanf("%d", &i);
    return i;
}

long long llin() {
    long long i;
    scanf("%lld", &i);
    return i;
}

double din() {
    double i;
    scanf("%lf", &i);
    return i;
}

char cin() {
    char c;
    scanf("%c", &c);
    return c;
}

void stin(char *s) {
    scanf("%s", s);
}

void iout(int i) {
    printf("%d\n", i);
}

void llout(long long i) {
    printf("%lld\n", i);
}

void dout(double i) {
    printf("%lf\n", i);
}

void cout(char c) {
    printf("%c\n", c);
}

void stout(char *s) {
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
    int r = llgcd(a, b);
    a /= r;
    return a * b;
}

/*
    long long型の最大公約数
*/

long long llgcd(long long a, long long b) {
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

long long lllcm(long long a, long long b) {
    long long r = llgcd(a, b);
    a /= r;
    return a * b;
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
