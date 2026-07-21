#include<stdio.h>
#define MAX 25
#define NIL -1

struct Node {
    int p, l, r;
};

Node T[MAX];
int D[MAX], H[MAX];

void print(int num) {
    int deg, s;
    if (T[num].l!=-1 && T[num].r!=-1) deg=2;
    else if (T[num].l==-1 && T[num].r==-1) deg=0;
    else deg=1;

    if (T[num].p==-1) s=-1;
    else if (T[T[num].p].l!=num) s=T[T[num].p].l;
    else s=T[T[num].p].r;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", num, T[num].p, s, deg, D[num], H[num]);

    if (T[num].p==-1) printf("root\n");
    else if (T[num].l!=-1 || T[num].r!=-1) printf("internal node\n");
    else printf("leaf\n");
}

int depth_height(int num, int depth) {
    int m_d1=-1, m_d2=-1;
    D[num] = depth;
    if (T[num].l!=-1) m_d1 = depth_height(T[num].l, depth+1);
    if (T[num].r!=-1) m_d2 = depth_height(T[num].r, depth+1);
    
    if (m_d1==-1 && m_d2==-1){
        H[num] = 0;
        return depth;
    } else if (m_d1>=m_d2) {
        H[num] = m_d1-depth;
        return m_d1;
    } else {
        H[num] = m_d2-depth;
        return m_d2;
    }
}

int main() {
    int j, n, num;
    scanf("%d", &n);

    for (int i=0; i<n; i++) T[i].p=T[i].l=T[i].r=-1;

    for (int i=0; i<n; i++) {
        scanf("%d", &j);
        scanf("%d", &num);
        T[j].l = num;
        T[num].p = j;
        scanf("%d", &num);
        T[j].r = num;
        T[num].p = j;
    }

    while (T[num].p!=-1) num = T[num].p;
    j = depth_height(num, 0);

    for (int i=0; i<n; i++) {
        print(i);
    }
    return 0;
}
