#include <stdio.h>
#define SIZE 100
#define nil -1

typedef struct
{
    int par, right, left;
} node;

int n, dep[SIZE], hei[SIZE];
node t[SIZE];

int max(int, int);
int height(int);
void depth(int, int);
int sibling(int);

int main()
{
    int i, root = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        t[i].par = t[i].left = t[i].right = nil;

    for (i = 0; i < n; i++)
    {
        int id, l, r;
        scanf("%d %d %d", &id, &l, &r);
        t[id].left = l;
        t[id].right = r;
        if (l != nil)
            t[l].par = id;
        if (r != nil)
            t[r].par = id;
    }

    for (i = 0; i < n; i++)
        if (t[i].par == nil)
            root = i;

    depth(root, 0);

    for (i = 0; i < n; i++)
    {
        int degcnt = 0;
        if (t[i].left != nil)
            degcnt++;
        if (t[i].right != nil)
            degcnt++;
        printf("node %d: parent = %d, ", i, t[i].par);
        printf("sibling = %d, ", sibling(i));
        printf("degree = %d, ", degcnt);
        printf("depth = %d, ", dep[i]);
        printf("height = %d, ", height(i));

        if (t[i].par == nil)
            printf("root\n");
        else if (t[i].left == nil && t[i].right == nil)
            printf("leaf\n");
        else
            printf("internal node\n");
    }

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int height(int u)
{
    int a = 0, b = 0;
    if (t[u].left != nil)
        a = height(t[u].left)+1;
    
    if(t[u].right != nil)
        b = height(t[u].right)+1;

    return max(a,b);
}

void depth(int u, int d)
{
    if (u == nil)
        return;
    dep[u] = d;
    depth(t[u].left, d + 1);
    depth(t[u].right, d + 1);
}

int sibling(int u)
{
    int tmp;
    tmp = t[u].par;
    if (tmp == nil)
        return nil;

    if (t[tmp].left != u && t[tmp].left != nil)
        return t[tmp].left;

    if (t[tmp].right != u && t[tmp].right != nil)
        return t[tmp].right;

    return nil;
}
