/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void) {
  Node second = { 25, NULL };
  Node first = { 59, &second };
  printf("%d\n", first.next->data);
  return 0;
}
