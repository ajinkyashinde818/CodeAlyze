#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
	Node second = { 16, NULL };
	Node first = { 75, &second };
	printf("%d\n", first.left->data);
	return 0;
}
