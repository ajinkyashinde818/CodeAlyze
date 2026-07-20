/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
  Node second = { 27, NULL };
  Node first = { 57, &second };
  printf("%d\n", first.left->data);
  return 0;
}
