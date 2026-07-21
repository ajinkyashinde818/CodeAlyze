#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node* parent;
	int degree;
	int depth;
	int height;
	char type[15];
	
	int * child_list;
};
typedef struct Node * NodePointer;


void serach_depth (NodePointer ,int  ,NodePointer[]);

int main (){
	int n;
	scanf("%d\n",&n);
	
	//setting part
	NodePointer array [n];
	for (int i = 0; i < n;i++)
	{
		array[i] = (NodePointer) malloc (sizeof(struct Node));
		array[i]->parent = NULL;
		array[i]->degree = 0;
		strcpy(array[i]->type,"internal node");
	}
	
	//input part
	for (int i = 0; i < n;i++)
	{
		int id;
		scanf("%d ",&id);
		array[id]->key = id;
		int child_num;
		scanf("%d" ,&child_num);
		array[id]->child_list = (int *) malloc (child_num * sizeof(int));
		
		if ( child_num == 0){
			strcpy(array[id]->type ,"leaf");
		}else {
			for (int j = 0; j < child_num; j++){
				int child_id;
				scanf(" %d" ,&child_id);
				array[id]->child_list[j] = child_id;
				array[child_id]->parent = array[id];
				array[id]->degree++;
			}
		}

	}
	
	//search part
		for (int i = 0; i < n;i++)
	{
		if(array[i]->parent == NULL) {
			strcpy(array[i]->type ,"root");
			serach_depth(array[i],0 ,array); break;
		}
	}
	
	//print part
	for (int i = 0; i < n ;i++){
		printf("node %d: ",i);
		if (array[i] -> parent != NULL){
		printf("parent = %d, ",array[i]->parent->key);
		}else {
			printf("parent = -1, ");
		}
		printf("depth = %d, %s, [",array[i]->depth,array[i]->type );
		for ( int j = 0; j < array[i]->degree; j++){
			printf("%d" ,array[i]->child_list[j]);
			if ( j + 1 != array[i]->degree){printf(", ");}
		}
		printf("]\n");
	}
	
	return 0;
}

void serach_depth (NodePointer tag,int dep , NodePointer array[]){
	tag->depth = dep;
	if ( tag->degree == 0 ){tag->height = 0; return;}
	for ( int j = 0; j < tag->degree ; j++){
		serach_depth(array [ (tag->child_list[j]) ] , dep + 1 ,array);
	}
}
