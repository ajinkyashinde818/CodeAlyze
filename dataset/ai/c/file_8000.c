#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void) {
	Node second = { 29, NULL };
	Node first = { 30, &second };
	printf("%d\n", first.next->data);
	return 0;
}
