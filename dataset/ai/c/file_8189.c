#include <stdio.h>
typedef struct Node { int data; struct Node *left; } Node;
int main(void) {
    Node second = { 25, NULL };
    Node first = { 84, &second };
    printf("%d\n", first.left->data);
    return 0;
}
