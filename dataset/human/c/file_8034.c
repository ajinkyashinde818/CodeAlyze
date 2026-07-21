#include <stdio.h>
#include <stdlib.h>


#define SWAP(type, x, y) { type tmp = x; x = y; y = tmp; }

#define N (1000)

#define INF (N*N)

typedef struct priorityqueue_item {
  int value;
  int priority;
} PRIORITYQUEUE_ITEM;

typedef struct priorityqueue {
  PRIORITYQUEUE_ITEM items[N*N];
  int len;
  int value2index[N*N];
} PRIORITYQUEUE;

void priorityqueue_swap(PRIORITYQUEUE *q, int i, int j) {
  SWAP(PRIORITYQUEUE_ITEM, q->items[i], q->items[j]);
  q->value2index[q->items[i].value] = i;
  q->value2index[q->items[j].value] = j;
}

void priorityqueue_upheap(PRIORITYQUEUE *q, int i) {
  int parent;
  for (;; i = parent) {
		if (i == 0) break;
		parent = i/2;
		if (q->items[parent].priority <= q->items[i].priority) break;
		priorityqueue_swap(q, parent, i);
	}
}

void priorityqueue_downheap(PRIORITYQUEUE *q, int i) {
  int priorchild;
  for (;; i = priorchild) {
		if (2*i >= q->len) break;
    if (2*i+1 < q->len && q->items[2*i+1].priority < q->items[2*i].priority) priorchild = 2*i+1;
    else priorchild = 2*i;
		if (q->items[priorchild].priority >= q->items[i].priority) break;
		priorityqueue_swap(q, priorchild, i);
	}
}

void priorityqueue_push(PRIORITYQUEUE *q, PRIORITYQUEUE_ITEM x) {
  q->items[q->len] = x;
  q->len++;
  q->value2index[x.value] = q->len-1;
  priorityqueue_upheap(q, q->len-1);
}

PRIORITYQUEUE_ITEM priorityqueue_pop(PRIORITYQUEUE *q) {
  PRIORITYQUEUE_ITEM x = q->items[0];
  priorityqueue_swap(q, 0, q->len-1);
  q->len--;
  priorityqueue_downheap(q, 0);
  return x;
}

void priorityqueue_update(PRIORITYQUEUE *q, PRIORITYQUEUE_ITEM x) {
  q->items[q->value2index[x.value]] = x;
  priorityqueue_upheap(q, q->value2index[x.value]);
}

typedef struct adjacencylist {
  int node;
  int cost;
  struct adjacencylist *next;
} ADJACENCYLIST;

void dijkstra(ADJACENCYLIST *als[], int n, int s, int ds[]) {
  PRIORITYQUEUE q = {0};
  PRIORITYQUEUE_ITEM tmp;
  int u;
  for (int v = 0; v < n; v++) {
    if (v == s) ds[v] = 0;
    else ds[v] = INF;
    tmp.value = v;
    tmp.priority = ds[v];
    priorityqueue_push(&q, tmp);
  }
  while (q.len > 0) {
    u = priorityqueue_pop(&q).value;
    for (ADJACENCYLIST *al = als[u]; al != NULL; al = al->next) {
      if (ds[al->node] > ds[u] + al->cost) {
        ds[al->node] = ds[u] + al->cost;
        tmp.value = al->node;
        tmp.priority = ds[al->node];
        priorityqueue_update(&q, tmp);
      }
    }
  }
}

int tmp_i, ds[N*N];
char S[N][N];
ADJACENCYLIST *als[N*N];
ADJACENCYLIST tmp[24*N*N];

int main() {
  int H, W, Ch, Cw, Dh, Dw, s, g;
  scanf("%d%d%d%d%d%d", &H, &W, &Ch, &Cw, &Dh, &Dw);
  Ch--;
  Cw--;
  Dh--;
  Dw--;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf(" %c", &S[i][j]);
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') continue;
      for (int k = -2; k <= 2; k++) {
        for (int l = -2; l <= 2; l++) {
          if (i+k < 0 || i+k >= H || j+l < 0 || j+l >= W || (k == 0 && l == 0) || S[i+k][j+l] == '#') continue;
          tmp[tmp_i].node = (i+k)*W+j+l;
          if (abs(k)+abs(l) == 1) tmp[tmp_i].cost = 0;
          else tmp[tmp_i].cost = 1;
          tmp[tmp_i].next = als[i*W+j];
          als[i*W+j] = &tmp[tmp_i];
          tmp_i++;
        }
      }
    }
  }
  s = Ch*W+Cw;
  g = Dh*W+Dw;
  dijkstra(als, H*W, s, ds);
  if (ds[g] >= INF) printf("-1\n");
  else printf("%d\n", ds[g]);
  return 0;
}
