#include <stdio.h>
#define MAX 25

int Sibling(int);
int Degree(int);
int Depth(int);
int Height(int);

struct node
{
  int p;
  int l, r;
} typedef node;

node N[MAX];

int main()
{
    int i, j;
    int n, id;

    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        N[i].p = -1;
    }
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &id);
        scanf("%d %d", &N[id].l, &N[id].r);
        if(N[id].l != -1) N[N[id].l].p = id;
        if(N[id].r != -1) N[N[id].r].p = id;
    }
    
    for(i = 0; i < n; i++)
    {
        printf("node %d: ", i);
        printf("parent = %d, ", N[i].p);
        printf("sibling = %d, ", Sibling(i));
        printf("degree = %d, ", Degree(i));
        printf("depth = %d, ", Depth(i));
        printf("height = %d, ", Height(i));

        if(N[i].p == -1) printf("root\n");
        else if(N[i].l == -1 && N[i].r == -1) printf("leaf\n");
        else printf("internal node\n");
    }
    
    return 0;
}

int Sibling(int id)
{
	if(N[id].p == -1) return -1;
	
	if(N[N[id].p].l != id) return N[N[id].p].l;
	else return N[N[id].p].r;
}

int Degree(int id)
{
	int count = 0;
	
	if(N[id].l != -1) count++;
	if(N[id].r != -1) count++;
	
	return count;
}

int Depth(int id)
{
	int count = 0;

    while(N[id].p != -1)
    {
        count++;
        id = N[id].p;
    }
    
    return count;
}

int Height(int id)
{
	int lc, rc;
	
	if(id == -1) return -1;
	
	lc = Height(N[id].l);
	rc = Height(N[id].r);
	
	if(lc > rc) return lc + 1;
	else return rc + 1;
}
