#include<stdio.h>

#define S_SIZE 100001

char s[S_SIZE];

typedef struct{
  char c;
  struct Deque *prev;
  struct Deque *next;

} Deque;

int main(void) {
  int query_size,str_size;
  int reverse = 0;
  Deque *head,*tail,*tmp;
  head = (Deque *)malloc(sizeof(Deque));

  scanf("%s",s);
  scanf("%d",&query_size);

  head->c = s[0];
  head->next = NULL; head->prev = NULL;
  tail = head;

  str_size = strlen(s);
  for(int i = 1;i < str_size;i++) {
    tmp = (Deque *)malloc(sizeof(Deque));
    tmp->c = s[i];
    head->next = tmp;
    tmp->next = NULL;
    tmp->prev = head;
    head = tmp;
  };

  for(int i = 0;i < query_size;i++) {
    int t,f;
    char c;
    scanf("%d",&t);

    if(t==1) {
      reverse = (reverse == 0)? 1:0;
      continue;
    }
    scanf("%d %c",&f,&c);
    tmp = (Deque *)malloc(sizeof(Deque));
    tmp->c = c;
    if((f==1 && reverse == 1) || (f==2 && reverse == 0)) {
      // 末尾追加
      head->next = tmp;
      tmp->next = NULL;
      tmp->prev = head;
      head = tmp;
    } else {
      // 先頭追加
      tail->prev = tmp;
      tmp->next = tail;
      tmp->prev = NULL;
      tail = tmp;
    }
  }

  if(reverse == 0) {
    for(Deque *d = tail;d != NULL;d = d->next) {
      printf("%c",d->c);
    }
  } else {
    for(Deque *d = head;d != NULL;d = d->prev) {
      printf("%c",d->c);
    }
  }
}
