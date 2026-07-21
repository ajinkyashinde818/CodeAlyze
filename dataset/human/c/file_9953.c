#include<stdio.h>
#define MAX 100005
#define NIL -1

/*
 p: parent
 l: left-child
 r: right sibling
 */
struct Node{ int p, l, r;};
struct Node T[MAX]; // Tree
int *Child[MAX];

char type[3][20] = {
	"root",
	"internal node",
	"leaf"
};

void print(int u, int n){
	int p = T[u].p;
	int d = 0;
	int t = T[u].p;
	int i, j, z;
	int child[MAX];
	char *mes;
	int isfound;
	while(t != NIL) {
		t = T[t].p;
		d++;
	}
	
	if(p==NIL) {
		mes = type[0];
	} else if(T[u].l == NIL) {
		mes = type[2];
	} else {
		mes = type[1];
	}

	printf("node %d: parent = %d, depth = %d, %s, [", u, p, d, mes);
	for(i=0;i<Child[u][0];i++) {
		if(i==0) {
			printf("%d", Child[u][i+1]);
		} else {
			printf(", %d", Child[u][i+1]);
		}
	}

	printf("]\n");
}

int main(void){
    int i, j, d, v, c, n, old;

    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) {
        T[i].p = T[i].l = T[i].r = NIL;
    }

    for ( i = 0; i < n; i++ ){
        scanf("%d %d", &v, &d);
        Child[v] = (int*)malloc(sizeof(int)*(d+1));
        Child[v][0] = d;
        for ( j = 0; j < d; j++ ){
            scanf("%d", &c);
            Child[v][j+1] = c;
            if(j==0) {
            	T[v].l = c;
            }
            T[c].p = v;
            if(j > 0) {
            	T[c].r = old;
            }
            old = c;
        }
    }
    
    for ( i = 0; i < n; i++ ) print(i, n);
    return 0;
}
