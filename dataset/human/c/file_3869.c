#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}pair;

int root(int a, int *array){
	if(array[a] == a){
		return a;
	}
	else{
		array[a] = root(array[a], array);
		return array[a];
	}
}

void combine(int a, int b, int *array, int *array_rank){
	int a_root = root(a, array);
	int b_root = root(b, array);
	if(a_root == b_root){
		return;
	}
	else if(array_rank[a_root] < array_rank[b_root]){
		array[a_root] = b_root;
		array_rank[b_root] += array_rank[a_root];
	}
	else{
		array[b_root] = a_root;
		array_rank[a_root] += array_rank[b_root];
	}
}

int compare(pair a, pair b){
	if(a.x < b.x){
		return 1;
	}
	else if(a.x > b.x){
		return -1;
	}
	else{
		if(a.y < b.y){
			return 1;
		}
		else if(a.y > b.y){
			return -1;
		}
		else{
			return 0;
		}
	}
}
#define datatype pair

typedef struct node_sub{
	datatype val;
	int num;
	int height;
	struct node_sub *left;
	struct node_sub *right;
}node;

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int node_height(node *t){
	if(t == NULL){
		return 0;
	}
	else{
		return t->height;
	}
}

node *build_node(datatype val, int num, node *left, node *right){
	node *newr;
	int left_h = node_height(left);
	int right_h = node_height(right);
	if(left_h > right_h + 1){
		node *ll = left->left;
		node *lr = left->right;
		if(node_height(ll) < node_height(lr)){
			newr = build_node(lr->val, lr->num, build_node(left->val, left->num, ll, lr->left), build_node(val, num, lr->right, right));
			free(lr);
		}
		else{
			newr = build_node(left->val, left->num, ll, build_node(val, num, lr, right));
		}
		free(left);
	}
	else if(right_h > left_h + 1){
		node *rr = right->right;
		node *rl = right->left;
		if(node_height(rr) < node_height(rl)){
			newr = build_node(rl->val, rl->num, build_node(val, num, left, rl->left), build_node(right->val, right->num, rl->right, rr));
			free(rl);
		}
		else{
			newr = build_node(right->val, right->num, build_node(val, num, left, rl), rr);
		}
		free(right);
	}
	else{
		newr = (node *)malloc(sizeof(node));
		newr->val = val;
		newr->num = num;
		newr->height = max(left_h, right_h) + 1;
		newr->left = left;
		newr->right = right;
	}
	return newr;
}

node *add_val(datatype val, node *t){
	if(t == NULL){
		return build_node(val, 1, NULL, NULL);
	}
	datatype t_val = t->val;
	int t_num = t->num;
	node *t_left = t->left;
	node *t_right = t->right;
	free(t);
	int comp = compare(val, t_val);
	if(comp == 0){
		return build_node(val, t_num + 1, t_left, t_right);
	}
	else if(comp == 1){
		return build_node(t_val, t_num, add_val(val, t_left), t_right);
	}
	else{
		return build_node(t_val, t_num, t_left, add_val(val, t_right));
	}
}

int return_num(datatype val, node *t){
	if(t == NULL){
		return 0;
	}
	int comp = compare(val, t->val);
	if(comp == 0){
		return t->num;
	}
	else if(comp == 1){
		return return_num(val, t->left);
	}
	else{
		return return_num(val, t->right);
	}
}

int main(){
	int N, K, L, i;
	scanf("%d%d%d", &N, &K, &L);
	int *load = (int *)malloc(sizeof(int) * N);
	int *load_rank = (int *)malloc(sizeof(int) * N);
	int *train = (int *)malloc(sizeof(int) * N);
	int *train_rank = (int *)malloc(sizeof(int) * N);
	node *ans = NULL;
	for(i = 0; i < N; i++){
		load[i] = i;
		load_rank[i] = 1;
		train[i] = i;
		train_rank[i] = 1;
	}
	int p, q;
	for(i = 0; i < K; i++){
		scanf("%d%d", &p, &q);
		combine(p - 1, q - 1, load, load_rank);
	}
	int r, s;
	for(i = 0; i < L; i++){
		scanf("%d%d", &r, &s);
		combine(r - 1, s - 1, train, train_rank);
	}
	free(load_rank);
	free(train_rank);
	pair P;
	for(i = 0; i < N; i++){
		P.x = root(i, load);
		P.y = root(i, train);
		ans = add_val(P, ans);
	}
	for(i = 0; i < N; i++){
		P.x = root(i, load);
		P.y = root(i, train);
		printf("%d ", return_num(P, ans));
	}
	return 0;
}
