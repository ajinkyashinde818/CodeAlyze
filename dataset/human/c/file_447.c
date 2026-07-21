#include <stdio.h>
#include <math.h>

#define SQ(x) ((x)* (x))
#define EPS (1e-5)

typedef struct {
    double x;
    double y;
    double r;
} CIRCLE;

double size(CIRCLE a)
{
    return (sqrt(SQ(a.x) + SQ(a.y)));
}

CIRCLE minus(CIRCLE a, CIRCLE b)
{
    CIRCLE res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    
    return (res);
}

double scalarProduct(CIRCLE a, CIRCLE b)
{
    return (a.x * b.x + a.y * b.y);
}

double determinant(CIRCLE a, CIRCLE b)
{
    return (a.x * b.y - a.y * b.x);
}

double segmentDistance(CIRCLE a, CIRCLE b, CIRCLE c)
{
    if (scalarProduct(minus(b, a), minus(c, a)) < EPS){
        return size(minus(c, a));
    }
    if (scalarProduct(minus(a, b), minus(c, b)) < EPS){
        return size(minus(c, b));
    }
    
    return (fabs(determinant(minus(b, a), minus(c, a))) / size(minus(b, a)));
}

int inCircle(CIRCLE a, CIRCLE c)
{
    return (SQ(a.x - c.x) + SQ(a.y - c.y) - SQ(c.r) <= EPS);
}

int main(void)
{
    int n, m;
    int i, j;
    CIRCLE circ[100];
    CIRCLE t, s;
    int flag;
    
    while (1){
        scanf("%d", &n);
        
        if (n == 0){
            break;
        }
        
        for (i = 0; i < n; i++){
            scanf("%lf%lf%lf", &circ[i].x, &circ[i].y, &circ[i].r);
        }
        
        scanf("%d", &m);
        
        for (i = 0; i < m; i++){
            scanf("%lf%lf%lf%lf", &t.x, &t.y, &s.x, &s.y);
            flag = 0;
            for (j = 0; j < n; j++){
                if (inCircle(s, circ[j]) ^ inCircle(t, circ[j]) || (!(inCircle(s, circ[j]) & inCircle(t, circ[j])) && segmentDistance(s, t, circ[j]) - circ[j].r < EPS)){
                    flag |= 1;
                }
            }
            
            if (flag == 1){
                printf("Safe\n");
            }
            else {
                printf("Danger\n");
            }
        }
    }
    
    return (0);
}
