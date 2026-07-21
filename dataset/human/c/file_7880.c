#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int key;
	int priority;
	struct node *left;
	struct node *right;
}node;

node * Delete(node **,int);
node * _delete(node **,int);

int find(node *p,int x){

	while(p!=NULL){
		if(p->key == x)return 1;
		else if(p->key > x)p=p->left;
		else p=p->right;
	}
	
	return 0;
	
}


node * makenode(int x,int y){
	node *new=malloc(sizeof(node));
	new->key=x;
	new->priority=y;
	new->left=NULL;
	new->right=NULL;
	return new;
}

node *rightRotate(node *p){
	node *q=p->left;
	p->left=q->right;
	q->right=p;
	return q;
}

node *leftRotate(node *p){
	node *q=p->right;
	p->right=q->left;
	q->left=p;
	return q;
}


node* insert(node **t,int key,int priority){
	node *new;
	
	if((*t)==NULL)
		return new=makenode(key,priority);
	if ((*t)->key==key)
		return *t;
	
	if(key < (*t)->key){
		(*t)->left=insert(&(*t)->left,key,priority);
		if((*t)->priority < (*t)->left->priority)
			(*t)=rightRotate((*t));
	}
	else {
		(*t)->right=insert(&(*t)->right,key,priority);
		if((*t)->priority < (*t)->right->priority)
			(*t)=leftRotate((*t));
	}
	
	return *t;
}


node * Delete(node **t,int key){
	if((*t)==NULL)
		return NULL;
		
	if(key < (*t)->key)
		(*t)->left=Delete(&((*t)->left),key);
		
	else if(key > (*t)->key)
		(*t)->right=Delete(&((*t)->right),key);
		
	else return _delete(t,key);
	
	return *t;
}

node * _delete(node **t,int key){
	if((*t)->left==NULL && (*t)->right==NULL)
		return NULL;
	else if((*t)->left==NULL)
		(*t)=leftRotate(*t);
	else if((*t)->right==NULL)
		(*t)=rightRotate(*t);
	else {
		if((*t)->left->priority > (*t)->right->priority)
			(*t)=rightRotate(*t);
		else
			(*t)=leftRotate(*t);
	}
	return Delete(t,key);
}



int main(){
	int q,x,com;
	int num=0;
	node *root=NULL;
	srand((unsigned)time(NULL));
	
	scanf("%d",&q);
	
	for(int i=0;i<q;i++){
		scanf("%d %d",&com,&x);
		
		if(com==0){
			if(!find(root,x)){
				root=insert(&root,x,rand()%200001);
				num++;
			}
			printf("%d\n",num);
		}
		else if(com==1){
			if(find(root,x))printf("1\n");
			else printf("0\n");
		}
		
		else {
			if(find(root,x)){
				root=Delete(&root,x);
				num--;
			}
		}
		
	}
		
	return 0;
	
}
