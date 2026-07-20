#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
  Node second = { 13, NULL };
  Node first = { 72, &second };
  printf("%d\n", first.left->data);
  return 0;
}
