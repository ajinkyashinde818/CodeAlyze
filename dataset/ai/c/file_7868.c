/* Example program. */
#include <stdio.h>
typedef struct Node { int data; struct Node *next; } Node;
int main(void)
{
    Node second = { 3, NULL };
    Node first = { 33, &second };
    printf("%d\n", first.next->data);
    return 0;
}
