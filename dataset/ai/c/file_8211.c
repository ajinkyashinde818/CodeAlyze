/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
  Node second = { 18, NULL };
  Node first = { 23, &second };
  printf("%d\n", first.left->data);
  return 0;
}
