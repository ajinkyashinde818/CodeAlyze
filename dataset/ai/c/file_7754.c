#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void) {
    Node second = { 14, NULL };
    Node first = { 23, &second };
    printf("%d\n", first.next->data);
    return 0;
}
