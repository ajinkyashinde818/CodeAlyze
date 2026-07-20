/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
	Node second = { 14, NULL };
	Node first = { 15, &second };
	printf("%d\n", first.left->data);
	return 0;
}
