#include <stdio.h>
#define N 10000
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};
struct Node T[N];
int depth[N], height[N];

int setDepth(int );
int setSibling(int );
void print(int );
int main(){
  int n, i, id, c, parent, left, right;
	scanf("%d", &n);
    
  for( i = 0; i < n; i++ ) {
		T[i].parent = NIL;
	}
  for( i = 0; i < n; i++ ) {
   	scanf("%d %d %d", &id, &left, &right);
		T[id].left = left;
		T[id].right = right;
		if( left != NIL ){
			T[left].parent = id;
		}
		if( right != NIL ){
			T[right].parent = id;
		}
	}

	for( i = 0; i < n; i++ ) {
		depth[i] = setDepth(i);
		height[i] = 0;
	}

	for( i = 0; i < n; i++ ){
		if( T[i].left == NIL && T[i].right == NIL ){
			height[i] = 0;
			parent = T[i].parent;
			c = 1;
			while( 1 ){
				if( parent == NIL ){
					break;
				}
				if( height[parent] < c ){
					height[parent] = c;
				}
				c++;
				parent = T[parent].parent;
			}
		}
	}
	for( i = 0; i < n; i++ ){
		print(i);
	}

  return 0;
}

int setDepth(int id){
	int i = 0;
	while(1){
		id = T[id].parent;
		if( id == NIL ) {
			break;
		}
		i++;
	}
	return i;
}

int setSibling(int id){
	if(T[id].parent == NIL){
		return NIL;
	}
	if(T[T[id].parent].left != id && T[T[id].parent].left != NIL){
		return T[T[id].parent].left;
	}
	if(T[T[id].parent].right != id && T[T[id].parent].right != NIL){
		return T[T[id].parent].right;
	}
	return NIL;
}

void print(int id){
	int degree = 0;
	printf("node %d: parent = %d, sibling = %d, ", id, T[id].parent, setSibling(id));
	if(T[id].left != NIL){
		degree++;
	}
	if(T[id].right != NIL){
		degree++;
	}
	printf("degree = %d, depth = %d, height = %d, ", degree, depth[id], height[id]);

	if( T[id].parent == NIL ){
		printf("root\n");
	}
	else if( T[id].left == NIL && T[id].right == NIL ){
		printf("leaf\n");
	}
	else{
		printf("internal node\n");
	}
}
