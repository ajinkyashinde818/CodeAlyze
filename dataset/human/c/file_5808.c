#include <stdio.h>

#define MAX_VALUE (200000)

int main(void) {
        int i, j;
        int num_value = 0;
        int value_currency[MAX_VALUE];
        int value_def, value_min;

        scanf("%d", &num_value);

        scanf("%d", &value_currency[0]);
        scanf("%d", &value_currency[1]);
        value_def = value_currency[1] - value_currency[0];
        value_min = value_currency[0];

        if (value_currency[1] < value_min)
                value_min = value_currency[1];

        for ( i = 2; i < num_value; i++) {
                scanf("%d", &value_currency[i]);
                if (value_def <= (value_currency[i] - value_min))
                        value_def = (value_currency[i] - value_min);
                if (value_currency[i] < value_min)
                        value_min = value_currency[i];
        }

        printf("%d\n", value_def);

        return 0;
}
