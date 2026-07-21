#include <stdio.h>
#include <stdlib.h>


typedef struct tree_t{
	int parent;
	int depth;
	int box_n;
	int *box;
} TREE_T;

TREE_T *TREE;


void Add_depth(TREE_T *box, int soeji, int depth)
{
	int i;

	box[soeji].depth = depth;

	for(i = 0; i < box[soeji].box_n; i++)
		Add_depth(box, box[soeji].box[i], depth + 1);
}


int main()
{
	int n;
	int id, k, sub_id;
	int i, j;

	scanf("%d", &n);

	TREE = (TREE_T *)malloc(sizeof(TREE_T) * n);

	for(i = 0; i < n; i++)
		TREE[i].parent = -1;

	for(i = 0; i < n; i++){
		scanf("%d %d", &id, &k);
		TREE[id].box_n = k;
		TREE[id].box = (int *)malloc(sizeof(int) * k);

		if(k){
			for(j = 0; j < k; j++){
				scanf("%d", &sub_id);
				TREE[id].box[j] = sub_id;
				TREE[sub_id].parent = id;
			}
		}
	}

	// depthの更新
	i = -1;
	while(TREE[++i].parent != -1);
	Add_depth(TREE, i, 0);

	/* 節情報の表示 */
	for(i = 0; i < n; i++){
		printf("node %d: parent = %d, depth = %d, ", i, TREE[i].parent, TREE[i].depth);

		if(TREE[i].parent == -1)
			printf("root, ");
		else if(TREE[i].box_n >= 1)
			printf("internal node, ");
		else
			printf("leaf, ");

		printf("[");
		for(j = 0; j < TREE[i].box_n; j++){
			printf("%d", TREE[i].box[j]);
			if(j != TREE[i].box_n - 1)
				printf(", ");
		}
		printf("]\n");
	}

	return 0;
}
