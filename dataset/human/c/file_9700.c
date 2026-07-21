#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int bronum;
	int mo;
	int *bro;
}Node;
int main() {
	Node *n;
	int i, j, ndnum, mo, bronum,node,temp,dep;
	//一番始めに数が与えられる。それをこうぞうたいはいれつにいれる
	scanf("%d", &ndnum);
	n = malloc(sizeof(Node)*ndnum);
	for ( i = 0; i < ndnum; i++)
	{
		n[i].mo = -1;
	}
	for (i = 0; i < ndnum; i++)//この回数はただの何回回すかだけ。中に入るデータは関係ない
	{
		scanf("%d%d", &node, &bronum);
		n[node].bronum = bronum;
		/*n(node)で順番に入ってくれる。（データの数）
		bronumはbroと末端かを判別させる*/
		if (bronum != 0)
		{
			n[node].bro = malloc(sizeof(int)*bronum);
		}
		for ( j = 0; j < bronum; j++)
		{
			scanf("%d",&temp);
			n[node].bro[j] = temp;
			n[temp].mo = node;
			/*nの番号が入ってるデータと一緒になっている。
			兄弟のデータが入っているｎの数は兄弟の実際のデータの親に当たる*/
		}
	}
	for ( i = 0; i < ndnum; i++)
	{
		dep = 0;
		for ( j = i; n[j].mo != -1; j = n[j].mo)//下からたどっていっているイメージ
		{
			dep += 1;
		}
		printf("node %d: parent = %d, depth = %d, ", i, n[i].mo, dep);
		if (dep == 0)
		{
			printf("root, ");
		}
		else if (n[i].bronum != 0)
		{
			printf("internal node, ");
		}
		else
		{
			printf("leaf, ");
		}
		printf("[");
		for ( j = 0; j < n[i].bronum; j++)
		{
			if (j == 0)
			{
				printf("%d", n[i].bro[j]);
			}
			else
			{
				printf(", %d", n[i].bro[j]);
			}
		}
		printf("]\n");
		free(n[i].bro);
	}
	free(n);
	return 0;
}
