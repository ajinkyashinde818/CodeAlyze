#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
	Node second = { 21, NULL };
	Node first = { 80, &second };
	printf("%d\n", first.left->data);
	return 0;
}
