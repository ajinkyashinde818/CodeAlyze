#include <stdio.h>

#define N 25

typedef struct{
  int id,p,l,r,sibling,degree,depth,height;
}Node;

Node node[N];

int calc_degree(Node);
void calc_fa(int);
void calc_depth(int, int);
int calc_height(int);

int main(){
	int n, i, id, root = 0;;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&id);
	node[id].id = id;
	node[id].p = node[id].sibling = -1;
    scanf("%d %d",&node[id].l,&node[id].r);
  }
  for (i = 0; i < n; i++) {
	  node[i].degree = calc_degree(node[i]);
  }
  calc_fa(n);
  for (i = 0; i < n; i++) {
	  if (node[i].p == -1) {
		  root = i;
		  break;
	  }
  }

  calc_depth(root, 0);
  calc_height(root);

  for (i = 0; i < n; i++){
	  printf("node %d: ",node[i].id);
	  printf("parent = %d, ", node[i].p);
	  printf("sibling = %d, ", node[i].sibling);
	  printf("degree = %d, ", node[i].degree);
	  printf("depth = %d, ", node[i].depth);
	  printf("height = %d, ", node[i].height);
	  if (i == root) printf("root\n");
	  else if (node[i].degree == 0) printf("leaf\n");
	  else printf("internal node\n");
  }
  return 0;
}

int calc_degree(Node n) {
	if (n.l != -1 && n.r != -1) return 2;
	if (n.l != -1 || n.r != -1) return 1;
	return 0;
}

void calc_fa(int n) {
	int i;
	for (i = 0; i < n; i++) {
		//parent
		//node[i].p = -1;
		if (node[i].l != -1) node[node[i].l].p = node[i].id;
		if (node[i].r != -1) node[node[i].r].p = node[i].id;
	}
	for(i=0; i<n; i++){
		//sibling
		//node[i].sibling = -1;
		if (node[node[i].p].l == node[i].id)
			node[i].sibling = node[node[i].p].r;
		if (node[node[i].p].r == node[i].id)
			node[i].sibling = node[node[i].p].l;
		if (node[i].p == -1) node[i].sibling = -1;
	}
}

void calc_depth(int now_id, int now_depth) {
	if (calc_degree(node[now_id]) == 0) {
		node[now_id].depth = now_depth;
		return;
	}
	if (node[now_id].l != -1) {
		calc_depth(node[now_id].l, now_depth + 1);
	}
	if (node[now_id].r != -1) {
		calc_depth(node[now_id].r, now_depth + 1);
	}
	node[now_id].depth = now_depth;
}

int calc_height(int now_id) {
	int lh, rh;
	if (node[now_id].degree == 0) {
		node[now_id].height = 0;
		return 0;
	}
	else {
		lh = calc_height(node[now_id].l) + 1;
		rh = calc_height(node[now_id].r) + 1;
		if (lh > rh) {
			node[now_id].height = lh;
			return lh;
		}
		else {
			node[now_id].height = rh;
			return rh;
		}
	}
}
