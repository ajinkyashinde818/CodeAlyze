#include <stdio.h>
#include <stdlib.h>
#define dag_valtype int
#define graph_valtype int

typedef struct graph_edge_sub graph_edge;

typedef struct {
	int num;
	int next_num;
	graph_edge *next;
	int prev_num;
}graph_vertex_sub;

struct graph_edge_sub{
	graph_vertex_sub *v;
	int w;
	graph_edge *next;
};

typedef struct graph_v_sub graph_vertex;

struct graph_v_sub{
	int num;
	graph_valtype val;
	int next_num;
	graph_vertex **next;
	int *next_weight;
	int prev_num;
	graph_vertex **prev;
	int *prev_weight;
};

typedef struct {
	int N;
	graph_vertex_sub **v_s;
	graph_vertex **v;
}graph;

//頂点数N, 各頂点の初期値ini_valのグラフを作る
graph *make_graph(int N, graph_valtype ini_val){
	int i;
	graph *g = (graph *)malloc(sizeof(graph));
	g->N = N;
	g->v_s = (graph_vertex_sub **)malloc(sizeof(graph_vertex_sub *) * N);
	g->v = (graph_vertex **)malloc(sizeof(graph_vertex *) * N);
	for(i = 0; i < N; i++){
		(g->v_s)[i] = (graph_vertex_sub *)malloc(sizeof(graph_vertex_sub));
		(g->v_s)[i]->num = i;
		(g->v_s)[i]->next_num = 0;
		(g->v_s)[i]->next = NULL;
		(g->v_s)[i]->prev_num = 0;
		(g->v)[i] = (graph_vertex *)malloc(sizeof(graph_vertex));
		(g->v)[i]->num = i;
		(g->v)[i]->val = ini_val;
		(g->v)[i]->next_num = 0;
		(g->v)[i]->next = NULL;
		(g->v)[i]->next_weight = NULL;
		(g->v)[i]->prev_num = 0;
		(g->v)[i]->prev = NULL;
		(g->v)[i]->prev_weight = NULL;
	}
	return g;
}

//グラフgの頂点aから頂点bに重みwの有向辺を張る (0 <= a, b <= N - 1)
void set_edge_graph(int a, int b, int w, graph *g){
	graph_edge *new1 = (graph_edge *)malloc(sizeof(graph_edge));
	new1->v = (g->v_s)[b];
	new1->w = w;
	new1->next = (g->v_s)[a]->next;
	(g->v_s)[a]->next = new1;
	(g->v_s)[a]->next_num++;
	(g->v_s)[b]->prev_num++;
}

//set_edge_graph後に呼び出す
void build_graph(graph *g){
	int i;
	graph_vertex_sub **v_s = g->v_s;
	graph_vertex **v = g->v;
	graph_vertex *nowv;
	graph_edge *nowe;
	for(i = 0; i < g->N; i++){
		v[i]->next = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->next_num);
		v[i]->next_weight = (int *)malloc(sizeof(int) * v_s[i]->next_num);
		v[i]->prev = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->prev_num);
		v[i]->prev_weight = (int *)malloc(sizeof(int) * v_s[i]->prev_num);
	}
	for(i = 0; i < g->N; i++){
		nowv = v[i];
		for(nowe = v_s[i]->next; nowe != NULL; nowe = nowe->next){
			(nowv->next)[nowv->next_num] = v[nowe->v->num];
			(nowv->next_weight)[nowv->next_num] = nowe->w;
			nowv->next_num++;
			(v[nowe->v->num]->prev)[v[nowe->v->num]->prev_num] = nowv;
			(v[nowe->v->num]->prev_weight)[v[nowe->v->num]->prev_num] = nowe->w;
			v[nowe->v->num]->prev_num++;
		}
	}
}

typedef struct SCC_sub{
	int num; //強連結成分番号
	int vertex_num; //強連結成分に含まれる頂点の個数
	int *vertexs; //強連結成分に含まれる元のグラフでの頂点番号
	dag_valtype val;
	int next_num;
	struct SCC_sub **next;
	int *next_weight;
	int prev_num;
	struct SCC_sub **prev;
	int *prev_weight;
}SCC; //強連結成分(Strongly Connected Components)

typedef struct {
	int N;
	SCC **sorted_SCC; //topological sort済み
}DAG; //非閉路有向グラフ(Directed Acyclic Graph)

int dfs(int next_bt, int *used, int *bt, int *bt_inv, graph_vertex *v){
	if(used[v->num] == 1){
		return next_bt;
	}
	else{
		int i;
		used[v->num] = 1;
		for(i = 0; i < v->next_num; i++){
			next_bt = dfs(next_bt, used, bt, bt_inv, v->next[i]);
		}
		bt[v->num] = next_bt;
		bt_inv[next_bt] = v->num;
		return next_bt + 1;
	}
}

void dfs_rev1(int next_SCC_num, int *used, int *SCC_num, int *next_num, int *prev_num, graph_vertex *v){
	if(used[v->num] == 1){
		int i;
		used[v->num] = 2;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, v->prev[i]);
		}
		SCC_num[v->num] = next_SCC_num;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 1){
				next_num[v->num]++;
				prev_num[v->next[i]->num]++;
			}
		}
	}
}

void dfs_rev2(SCC *now_SCC, int *used, int *SCC_num, graph_vertex *v, DAG *dag){
	if(used[v->num] == 2){
		int i;
		SCC *next_SCC;
		used[v->num] = 3;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev2(now_SCC, used, SCC_num, v->prev[i], dag);
		}
		now_SCC->vertexs[now_SCC->vertex_num] = v->num;
		now_SCC->vertex_num++;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 2){
				next_SCC = dag->sorted_SCC[SCC_num[v->next[i]->num]];
				now_SCC->next[now_SCC->next_num] = next_SCC;
				now_SCC->next_weight[now_SCC->next_num] = v->next_weight[i];
				now_SCC->next_num++;
				next_SCC->prev[next_SCC->prev_num] = now_SCC;
				next_SCC->prev_weight[next_SCC->prev_num] = v->next_weight[i];
				next_SCC->prev_num++;
			}
		}
	}
}

DAG *build_DAG(graph *g, dag_valtype ini_val){
	int N = g->N, i;
	int *used = (int *)malloc(sizeof(int) * N);

	int *bt = (int *)malloc(sizeof(int) * N);
	int *bt_inv = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		used[i] = 0;
		bt[i] = -1;
		bt_inv[i] = -1;
	}
	int next_bt;
	for(i = 0, next_bt = 0; i < N; i++){
		next_bt = dfs(next_bt, used, bt, bt_inv, g->v[i]);
	}

	int *SCC_num = (int *)malloc(sizeof(int) * N);
	int *next_num = (int *)malloc(sizeof(int) * N);
	int *prev_num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		SCC_num[i] = 0;
		next_num[i] = 0;
		prev_num[i] = 0;
	}
	int next_SCC_num;
	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 1){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, g->v[bt_inv[i]]);
			next_SCC_num++;
		}
	}

	DAG *dag = (DAG *)malloc(sizeof(DAG));
	SCC *now_SCC;
	dag->N = next_SCC_num;
	dag->sorted_SCC = (SCC **)malloc(sizeof(SCC *) * dag->N);
	for(i = 0; i < dag->N; i++){
		dag->sorted_SCC[i] = (SCC *)malloc(sizeof(SCC));
		now_SCC = dag->sorted_SCC[i];
		now_SCC->num = i;
		now_SCC->vertex_num = 0;
		now_SCC->vertexs = NULL;
		now_SCC->val = ini_val;
		now_SCC->next_num = 0;
		now_SCC->next = NULL;
		now_SCC->next_weight = NULL;
		now_SCC->prev_num = 0;
		now_SCC->prev = NULL;
		now_SCC->prev_weight = NULL;
	}
	for(i = 0; i < N; i++){
		now_SCC = dag->sorted_SCC[SCC_num[i]];
		now_SCC->vertex_num++;
		now_SCC->next_num += next_num[i];
		now_SCC->prev_num += prev_num[i];
	}
	for(i = 0; i < dag->N; i++){
		now_SCC = dag->sorted_SCC[i];
		now_SCC->vertexs = (int *)malloc(sizeof(int) * now_SCC->vertex_num);
		now_SCC->next = (SCC **)malloc(sizeof(SCC *) * now_SCC->next_num);
		now_SCC->next_weight = (int *)malloc(sizeof(int) * now_SCC->next_num);
		now_SCC->prev = (SCC **)malloc(sizeof(SCC *) * now_SCC->prev_num);
		now_SCC->prev_weight = (int *)malloc(sizeof(int) * now_SCC->prev_num);
		now_SCC->vertex_num = 0;
		now_SCC->next_num = 0;
		now_SCC->prev_num = 0;
	}

	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 2){
			dfs_rev2(dag->sorted_SCC[next_SCC_num], used, SCC_num, g->v[bt_inv[i]], dag);
			next_SCC_num++;
		}
	}

	return dag;
}

int main(){
	int N, M, a, b, i, j, f0, f1;
	scanf("%d%d", &N, &M);
	graph *g = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		set_edge_graph(a - 1, b - 1, 1, g);
	}
	build_graph(g);
	DAG *dag = build_DAG(g, 0);
	f1 = 1;
	for(i = 0; i < dag->N; i++){
		SCC *scc = dag->sorted_SCC[i];
		printf("%d\n", scc->vertexs[0] + 1);
		f0 = 0;
		for(j = 0; j < scc->next_num; j++){
			if(scc->next[j]->num == i + 1){
				f0 = 1;
			}
		}
		if(f0 == 0 && i < dag->N - 1){
			f1 = 0;
		}
//		printf("(i, f1) = (%d, %d)\n", i, f1);
	}
	printf("%d\n", 1 - f1);
	return 0;
}
