#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} POINT;

POINT add[100000], minus[100000];
char group[2][100000];
int n;

int comp(const void *a, const void *b)
{
    POINT p, q;
    
    p = *(POINT *)a;
    q = *(POINT *)b;
    
    return (p.x - q.x);
}

int canDivide(int piv)
{
    int i;
    int a, b;
    
    for (i = 0; i < n; i++){
        group[0][i] = group[1][i] = 2;
    }
    group[0][add[0].y] = 0;
    //suppose distance will be given by |c[0][i] - c[0][j]|
    
    for (i = 0; i < n; i++){
        if (abs(add[i].x - add[0].x) > piv && abs(add[i].x - add[n - 1].x) > piv){
            return (0);
        }
        if (abs(add[i].x - add[0].x) > piv){
            group[0][add[i].y] = 1;
        }
        if (abs(add[i].x - add[n - 1].x) > piv){
            group[0][add[i].y] = 0;
        }
    }
    
    //suppose distance will be given by |c[1][i] - c[1][j]|
    
    group[1][minus[0].y] = 0;
    for (i = 0; i < n; i++){
        if (abs(minus[i].x - minus[0].x) > piv && abs(minus[i].x - minus[n - 1].x) > piv){
            return (0);
        }
        if (abs(minus[i].x - minus[0].x) > piv){
            group[1][minus[i].y] = 1;
        }
        if (abs(minus[i].x - minus[n - 1].x) > piv){
            group[1][minus[i].y] = 0;
        }
    }
    
    a = b = 0;
    for (i = 0; i < n; i++){
        if (group[0][i] == 2 || group[1][i] == 2){
            b++;
            continue;
        }
        if (group[0][i] != group[1][i]){
            a++;
        }
    }
    
    return (a == 0 || a + b == n);
}

int main(void)
{
    int i;
    int left, right, center;
    int x, y;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        add[i].x = x + y;
        minus[i].x = x - y;
        add[i].y = minus[i].y = i;
    }
    
    qsort(add, n, sizeof(POINT), comp);
    qsort(minus, n, sizeof(POINT), comp);
    
    left = 0;
    right = 400000;
    
    while (left != right){
        center = (left + right) / 2;
        if (canDivide(center)){
            right = center;
        }
        else {
            left = center + 1;
        }
    }
    
    printf("%d\n", right);
    
    return (0);
}
