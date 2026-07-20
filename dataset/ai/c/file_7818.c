#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void)
{
    Node second = { 20, NULL };
    Node first = { 4, &second };
    printf("%d\n", first.next->data);
    return 0;
}
