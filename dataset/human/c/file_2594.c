#include <stdio.h>
#include <stdlib.h>

int *init(int size, int init_value) {
    int *array = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; ++i) {
        *(array+i) = init_value;
    }
    return array;
}

int main()
{
    char input[3];
    if (scanf("%s", input) < 0) return 1;
    int i;
    int *count = init(3, 0);
    
    for (i = 0; i < 3; ++i)
    {
        switch (input[i]) {
            case 'a':
                count[0]++;
                break;
            case 'b':
                count[1]++;
                break;
            case 'c':
                count[2]++;
                break;
        }
    }

    if (count[0] == 1 && count[1] == 1 && count[2] == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
