#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 200000
#define BIRTHDAY 1009

typedef struct hash{
	int num;
	struct hash *next;
}hash;

void append(hash**, int);
void search(hash**, int);
void clean(hash**);
void possible();

int a_list[MAX_NUM] = {0};
int a_index = 0;
hash *hash_list[BIRTHDAY] = {NULL};

int main(void){
	int N, M;
	int a, b;
	int i;
	hash *p;

	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		if(a == 1){
			append(hash_list, b);
		}
		if(b == N){
			a_list[a_index++] = a;
		}
	}

	for(i=0; i<a_index; i++){
		search(hash_list, a_list[i]);
	}

	clean(hash_list);
	printf("IMPOSSIBLE");
	return 0;
}

void append(hash **list, int num){
	hash *p, *tmp;
	hash *item;
	tmp = NULL;

	for(p = list[num%BIRTHDAY]; p != NULL && p->num < num; p = p->next)
		tmp = p;

	item = (hash*)malloc(sizeof(hash));
	item->num = num;
	item->next = p;
	if(tmp == NULL)
		list[num%BIRTHDAY] = item;
	else
		tmp->next = item;
}

void search(hash **list, int num){
	hash *p;
	for(p = list[num%BIRTHDAY]; p != NULL && p->num <= num; p = p->next){
		if(p->num == num)
			possible();
	}
}

void possible(){
	clean(hash_list);
	printf("POSSIBLE");
	exit(0);
}

void clean(hash **list){
	int i;
	hash *p, *tmp;
	tmp = NULL;
	for(i = 0; i < BIRTHDAY; i++){
		for(p = list[i]; p != NULL; p = p->next){
			free(tmp);
			tmp = p;
		}
	}
}
