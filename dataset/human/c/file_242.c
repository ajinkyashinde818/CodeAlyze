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
int dfs(int v, int n, int *visited, int table[n][n]);
int gcd(int a, int b);
int lcm(int a, int b);
long long llgcd(long long a, long long b);
long long lllcm(long long a, long long b);

//main function
int main() {
    int n = iin(), i, haveZero = 0, mc = 0, min = INT_MAX, tmp;
    int a[n];
    long long total = 0;
    REP(i,n) {
        a[i] = iin();
        if (a[i] == 0) haveZero = 1;
        else if (a[i] < 0) mc++;
    }
    REP(i,n) {
        tmp = abs(a[i]);
        total += tmp;
        if (min > tmp) min = tmp;
    }
    if (haveZero) {
        llout(total);
    } else if (mc % 2) {
        llout(total - (min * 2));
    } else {
        llout(total);
    }


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

int dfs(int v, int n, int *visited, int table[n][n]) {
    int all_visited = 1, i;

    REP(i,n) {
        if (!visited[i]) {
            all_visited = 0;
            break;
        }
    }

    if (all_visited) {
        return 1;
    }

    int count = 0;

    REP(i,n) {
        if (!table[v][i]) continue;
        if (visited[i]) continue;

        visited[i] = 1;
        count += dfs(i, n, visited, table);
        visited[i] = 0;
    }

    return count;
}

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

int lcm(int a, int b) {
    int r = llgcd(a, b);
    a /= r;
    return a * b;
}

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

long long lllcm(long long a, long long b) {
    long long r = llgcd(a, b);
    a /= r;
    return a * b;
}
