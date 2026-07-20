#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void) {
  Node second = { 16, NULL };
  Node first = { 46, &second };
  printf("%d\n", first.next->data);
  return 0;
}
