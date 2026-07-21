#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 100000
#define MAXQ 200000

struct Cha{
	char c;
	struct Cha *pre;
	struct Cha *next;
};

int main(){
	struct Cha *head = NULL;
	struct Cha *last = NULL;
	char s[MAXLEN+5] = "\0";
	int len, q, i;
	int t, f, rev = 0;
	char c;
	struct Cha *tmp;

	scanf("%s", s);
	len = strlen(s);
	head = (struct Cha *)malloc(sizeof(struct Cha));
	head->c = s[0];
	head->pre = NULL;
	head->next = NULL;
	last = head;
	for(i=1; i<len; i++){
		tmp = (struct Cha *)malloc(sizeof(struct Cha));
		tmp->c = s[i];
		tmp->pre = last;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}

	scanf("%d", &q);
	for(i=0; i<q; i++){
		scanf("%d", &t);
		if(t == 1){
			tmp = head;
			head = last;
			last = tmp;
			rev = 1 - rev;
		}else{
			scanf("%d %c", &f, &c);
			tmp = (struct Cha *)malloc(sizeof(struct Cha));
			tmp->c = c;
			if(f == 1){
				if(rev == 0){
					tmp->pre = NULL;
					tmp->next = head;
					head->pre = tmp;
					head = tmp;
				}else{
					tmp->next = NULL;
					tmp->pre = head;
					head->next = tmp;
					head = tmp;
				}
			}else{
				if(rev == 0){
					tmp->next = NULL;
					tmp->pre = last;
					last->next = tmp;
					last = tmp;
				}else{
					tmp->pre = NULL;
					tmp->next = last;
					last->pre = tmp;
					last = tmp;
				}
			}
		}
	}

	for(tmp=head; tmp!=NULL; tmp=(rev == 0) ? tmp->next : tmp->pre){
		printf("%c", tmp->c);
	}

	return 0;
}
