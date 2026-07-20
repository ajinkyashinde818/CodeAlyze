#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
	Node second = { 6, NULL };
	Node first = { 65, &second };
	printf("%d\n", first.left->data);
	return 0;
}
