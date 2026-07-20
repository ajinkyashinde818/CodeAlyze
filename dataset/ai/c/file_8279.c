#include <stdio.h>
int main(void) {
    int graph[3][3] = {{0}};
    graph[0][1] = graph[1][0] = 1;
    printf("%d\n", graph[0][1]);
    return 0;
}
