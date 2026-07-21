#include <stdio.h>
#include <stdlib.h>
 
#define JUDGE 1000000007
#define BLANK 1
 
int N, M;
 
typedef struct 
{
    int type;
    int road;
} Stair;
 
void visit(Stair*);
 
int main()
{
    int i;
    char buf[256];
    fgets(buf, 256, stdin);
    sscanf(buf, "%d %d", &N, &M);
 
    Stair* p = (Stair*)malloc(sizeof(Stair) * N);
 
    for (i = 0; i < N; i++)
    {
        p[i].type = 0;
        p[i].road = 0;
    }
 
    int a = 0;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &a);
        p[a-1].type = BLANK;
    }
    
    if (p[0].type != BLANK || p[1].type != BLANK)
    {
        p[0].road = 1;
        p[1].road = 1;
        visit(p);
    }
    printf("%d\n", p[N-1].road % JUDGE);
 
    return 0;
}
 
void visit(Stair* p)
{
    int i;
    for (i = 0; i < N-2; i++)
    {
        if (p[i].type == BLANK) continue;
        if (p[i+1].type != BLANK)
        {
            p[i+1].road += p[i].road % JUDGE;
        }
        
        if (p[i+2].type != BLANK)
        {
            p[i+2].road += p[i].road % JUDGE;
        }
    }
 
    if (p[N-1].type != BLANK && p[N-2].type != BLANK)
    {
        p[N-1].road += p[N-2].road % JUDGE;
    }
 
    return;
}
