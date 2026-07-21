#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
	int parent, left, right;
};

struct Node t[MAX];
int n, d[MAX], h[MAX];

void setDepth(int u, int e)
{
	if(u == NIL) return;
	d[u] = e;
	setDepth(t[u].left, e+1);
	setDepth(t[u].right, e+1);
}

int setHeight(int u)
{
	int h1 = 0, h2 = 0;
	if(t[u].left != NIL) h1 = setHeight(t[u].left) + 1;
	if(t[u].right != NIL) h2 = setHeight(t[u].right) + 1;
	return h[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u)
{
	if(t[u].parent == NIL) return NIL;
	if(t[t[u].parent].left != u && t[t[u].parent].left != NIL)
		return t[t[u].parent].left;
	if(t[t[u].parent].right != u && t[t[u].parent].right != NIL)
		return t[t[u].parent].right;
	return NIL;
}

void print(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", t[u].parent);
	printf("sibling = %d, ", getSibling(u));
	int deg = 0;
	if(t[u].left != NIL) deg++;
	if(t[u].right != NIL) deg++;
	printf("degree = %d, ", deg);
	printf("depth = %d, ", d[u]);
	printf("height = %d, ", h[u]);
	
	if(t[u].parent == NIL)
	{
		printf("root\n");
	} else if(t[u].left == NIL && t[u].right == NIL)
	{
		printf("leaf\n");
	} else {
		printf("internal node\n");
	}
}

int main(){
	int v, l, r, root = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		t[i].parent = NIL;
	}
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &v, &l, &r);
		t[v].left = l;
		t[v].right = r;
		if(l != NIL) t[l].parent = v;
		if(r != NIL) t[r].parent = v;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(t[i].parent == NIL)
		{
			root = i;
		}
	}
	
	setDepth(root, 0);
	setHeight(root);
	
	for(int i = 0; i < n; i++)
	{
		print(i);
	}
	
	return 0;
}
