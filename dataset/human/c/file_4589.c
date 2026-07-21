#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) { return x > y ? x : y; }

typedef struct
{
	int parent;
	int depth;
	int height;
	int degree;
	int left;
	int right;
	int sibling;
} node;

int set_level(node *data, int i, int d)
{	
	data[i].depth  = d;
	data[i].height = 0;
	data[i].degree = 0;

	if(data[i].left != -1)
	{
		data[data[i].left].sibling = data[i].right;
		data[i].height = max(data[i].height, 1 + set_level(data, data[i].left, d+1));
		data[i].degree += 1;
	}
	if(data[i].right != -1)
	{
		data[data[i].right].sibling = data[i].left;
		data[i].height = max(data[i].height, 1 + set_level(data, data[i].right, d+1));
		data[i].degree += 1;
	}
	
	return data[i].height;
}

int main()
{
	int n, x;
	node data[25];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		data[i].parent  = -1;
		data[i].left    = -1;
		data[i].right   = -1;
		data[i].sibling = -1;
	}

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		scanf("%d %d", &data[x].left, &data[x].right);
		
		if(data[x].left != -1)
		{
			data[data[x].left].parent  = x;
		}
		if(data[x].right != -1)
		{
			data[data[x].right].parent  = x;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(data[i].parent == -1)
		{
			set_level(data, i, 0);
			break;
		}
	}
	
	for(int i = 0; i < n; ++i)
	{		
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
			i, data[i].parent, data[i].sibling, data[i].degree, data[i].depth, data[i].height);
		
		if(data[i].parent == -1)
		{
			printf("root\n");
		}
		else if(data[i].degree == 0)
		{
			printf("leaf\n");
		}
		else
		{
			printf("internal node\n");
		}
	}
}
