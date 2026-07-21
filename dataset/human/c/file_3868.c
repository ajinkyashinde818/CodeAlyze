#include <stdio.h>
#include <stdlib.h>

void addEdge(int* count, int** list, int to) {
	int* newList = realloc(*list, sizeof(int) * (*count + 1));
	if (newList == NULL) exit(2);
	newList[(*count)++] = to;
	*list = newList;
}

int N;
int edgeCount[271828];
int* edges[271828];

int ufParent[271828];

void ufInit(void) {
	int i;
	for (i = 1; i <= N; i++) ufParent[i] = i;
}

int ufRoot(int node) {
	if (ufParent[node] == node) return node;
	return ufParent[node] = ufRoot(ufParent[node]);
}

void ufMerge(int a, int b) {
	int aRoot = ufRoot(a);
	int bRoot = ufRoot(b);
	if (aRoot != bRoot) ufParent[aRoot] = bRoot;
}

int currentGeneration;
int countGeneration[271828];
int count[271828];
int visited[271828];

int visitedCount;
int visitedList[271828];

int answer[271828];

void dfs(int node) {
	if (visited[node] != currentGeneration) {
		int root = ufRoot(node);
		int i;
		visited[node] = currentGeneration;
		visitedList[visitedCount++] = node;
		if (countGeneration[root] != currentGeneration) {
			countGeneration[root] = currentGeneration;
			count[root] = 0;
		}
		count[root]++;
		for (i = 0; i < edgeCount[node]; i++) {
			dfs(edges[node][i]);
		}
	}
}

int main(void) {
	int i;
	int K, L;
	if (scanf("%d%d%d", &N, &K, &L) != 3) return 1;
	for (i = 0; i < K; i++) {
		int p, q;
		if (scanf("%d%d", &p, &q) != 2) return 1;
		addEdge(&edgeCount[p], &edges[p], q);
		addEdge(&edgeCount[q], &edges[q], p);
	}
	ufInit();
	for (i = 0; i < L; i++) {
		int r, s;
		if (scanf("%d%d", &r, &s) != 2) return 1;
		ufMerge(r, s);
	}

	for (i = 1; i <= N; i++) {
		if (answer[i] == 0) {
			int j;
			currentGeneration++;
			visitedCount = 0;
			dfs(i);
			for (j = 0; j < visitedCount; j++) {
				answer[visitedList[j]] = count[ufRoot(visitedList[j])];
			}
		}
	}

	for (i = 1; i <= N; i++) {
		printf("%d%c", answer[i], i == N ? '\n' : ' ');
	}
	return 0;
}
