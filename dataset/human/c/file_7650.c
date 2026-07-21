#include<stdio.h>

#define MAX_LENGTH 32

int main(void)
{
        char line[MAX_LENGTH];
        int data;
        int i = 0;




        while (i <= 10000) {
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%d", &data);
                if (data == 0)
                        break;
                printf("Case %d: %d\n", ++i, data);

        }

        return 0;
}
