/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void) {
	Node second = { 15, NULL };
	Node first = { 45, &second };
	printf("%d\n", first.next->data);
	return 0;
}
