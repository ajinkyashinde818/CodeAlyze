#include<stdio.h>
#define MAX 100000

struct Node{
	int parent;
	int left;
	int right;
};

struct Node T[MAX];

int getDepth(int num){
	int depth = 0;
	
	for(depth = 0; T[num].parent != -1; depth++){
		num = T[num].parent;
	}
	return depth;
}

int main(void){
	int n, i, j;
	int num, deg, child, k = 0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){		//初期化
		T[i].parent = -1;
		T[i].left = -1;
		T[i].right = -1;
	}
	for(i=0; i<n; i++){
		scanf("%d%d", &num, &deg);
		
		for(j=0; j<deg; j++){
			scanf("%d", &child);
			if( j==0 ){ T[num].left = child; }
			else T[k].right = child;
			k = child;
			T[child].parent = num;
		}
	}
	for(i=0; i<n; i++){
		printf("node %d: parent = %d, depth = %d", i, T[i].parent, getDepth(i));
		
		if( getDepth(i) == 0 ){
			printf(", root, [");
		}
		else if( T[i].left == -1 ){
			printf(", leaf, [");
		}
		else{
			printf(", internal node, [");
		}
		
		j = T[i].left;
		
		while(j != -1){
			printf("%d", j);
			j = T[j].right;
			
				if( j != -1 ){ printf(", "); }
		}
		printf("]\n");
	}
	return 0;
}
