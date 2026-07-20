/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
  Node second = { 4, NULL };
  Node first = { 9, &second };
  printf("%d\n", first.left->data);
  return 0;
}
