#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
	struct Node* sibling;
	int degree;
	int depth;
	int height;
	char type[15]; 
};
typedef struct Node * NodePointer;


void serach_depth (NodePointer ,int );

int main (){
	int n;
	scanf("%d\n",&n);
	
	//setting part
	NodePointer array [n];
	for (int i = 0; i < n;i++)
	{
		array[i] = (NodePointer) malloc (sizeof(struct Node));
		array[i]->parent = NULL;
		array[i]->sibling = NULL;
		array[i]->left = NULL;
		array[i]->right = NULL;
		array[i]->degree = 0;
		strcpy(array[i]->type,"internal node");
	}
	
	//input part
	for (int i = 0; i < n;i++)
	{
		int id ,left_id,right_id;
		scanf("%d %d %d\n",&id,&left_id,&right_id);
		
		array[id]->key = id;
		if (left_id != -1){
			array[id]->left = array[left_id];
			array[left_id]->parent =  array[id];
			array[id]->degree++;
		}
		if (right_id != -1){
			array[id]->right = array[right_id];
			array[right_id]->parent =  array[id];
			array[id]->degree++;
		}
		if (left_id != -1 && right_id != -1){
			array[left_id]->sibling =  array[right_id];
			array[right_id]->sibling =  array[left_id];
		}
		if (left_id == -1 && right_id == -1){
			strcpy(array[id]->type ,"leaf");
		}
	}
	
	//search part
		for (int i = 0; i < n;i++)
	{
		if(array[i]->parent == NULL) {
			strcpy(array[i]->type ,"root");
			serach_depth(array[i],0); break;
		}
	}
	
	//print part
	for (int i=0; i<n ;i++){
		printf("node %d: ",i);
		if (array[i] -> parent != NULL){
		printf("parent = %d, ",array[i]->parent->key);
		}else {
			printf("parent = -1, ");
		}if (array[i] -> sibling != NULL){
		printf("sibling = %d, ",array[i]->sibling->key);
		}else {
			printf("sibling = -1, ");
		}
		printf("degree = %d, depth = %d, height = %d, %s\n",array[i]->degree,array[i]->depth,array[i]->height,array[i]->type );
	}
	
	return 0;
}

void serach_depth (NodePointer tag,int dep){
	tag->depth = dep;
	if(tag->left == NULL && tag->right == NULL){tag->height = 0; return;}
	if ( tag->left != NULL){serach_depth(tag->left , dep+1);}
	if ( tag->right != NULL){serach_depth(tag->right , dep+1);}
	if ( tag->left == NULL ){
		tag->height = tag->right->height + 1;
	}
	if ( tag->right == NULL){
		tag->height = tag->left->height + 1;
	}
	if ( tag->left != NULL && tag->right != NULL){
		if ( tag->left->height > tag->right->height){
			tag->height = tag->left->height + 1;
		}else {
			tag->height = tag->right->height + 1;
		}
	}
}
