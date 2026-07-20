#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
    Node second = { 10, NULL };
    Node first = { 69, &second };
    printf("%d\n", first.left->data);
    return 0;
}
