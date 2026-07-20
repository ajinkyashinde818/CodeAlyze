#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
  Node second = { 26, NULL };
  Node first = { 27, &second };
  printf("%d\n", first.left->data);
  return 0;
}
