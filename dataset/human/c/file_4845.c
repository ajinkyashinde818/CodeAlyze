#include <stdio.h>
#include <stdlib.h>


typedef struct tree_t{
	int parent;
	int sibling;
	int degree;
	int depth;
	int height;
	int left;
	int right;
} TREE_T;

TREE_T *TREE;


// 深さを調査
void Add_depth(TREE_T *box, int soeji, int depth)
{
	int i;

	box[soeji].depth = depth;

	if(box[soeji].left != -1)
		Add_depth(box, box[soeji].left, depth + 1);

	if(box[soeji].right != -1)
		Add_depth(box, box[soeji].right, depth + 1);
}


// 高さを調査
void Add_height(TREE_T *box, int soeji, int height)
{
	if(soeji == -1)
		return;

	if(height > box[soeji].height)
		box[soeji].height = height;

	Add_height(box, box[soeji].parent, height + 1);
}


int main()
{
	int n;
	int id;
	int left, right;
	int count;
	int i, j;

	scanf("%d", &n);

	// 初期化
	TREE = (TREE_T *)malloc(sizeof(TREE_T) * n);
	for(i = 0; i < n; i++){
		TREE[i].parent = -1;
		TREE[i].sibling = -1;
		TREE[i].left = TREE[i].right = -1;
		TREE[i].height = -1;
	}

	// 必要な情報を入れていく
	for(i = 0; i < n; i++){
		count = 0;
		scanf("%d %d %d", &id, &left, &right);
		TREE[id].left = left;
		TREE[id].right = right;

		if(left != -1){
			TREE[left].parent = id;
			TREE[left].sibling = right;
			count++;
		}
		if(right != -1){
			TREE[right].parent = id;
			TREE[right].sibling = left;
			count++;
		}

		TREE[id].degree = count;
	}

	// 根から辿って深さを調べる
	i = -1;
	while(TREE[++i].parent != -1);
	Add_depth(TREE, i, 0);

	// 葉から辿って高さを求める
	for(i = 0; i < n; i++){
		// leafである条件
		if(TREE[i].parent != -1 && TREE[i].degree == 0)
			Add_height(TREE, i , 0);
	}
	if(n == 1)
		TREE[0].height = 0;

	/* 表示 */
	for(i = 0; i < n; i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
		i, TREE[i].parent, TREE[i].sibling, TREE[i].degree, TREE[i].depth, TREE[i].height);

		if(TREE[i].parent == -1)
			printf("root\n");
		else if(TREE[i].left != -1 ||  TREE[i].right != -1)
			printf("internal node\n");
		else
			printf("leaf\n");

	}

	return 0;
}
