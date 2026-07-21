#include <stdio.h>
#include <string.h>

int main(void){
    char imp[100001];
    char five[5] = {0};
    char six[6] = {0};
    char seven[7] = {0};
    char dr[] = {'r','e','m','a','e','r','d'};
    char dm[] = {'m','a','e','r','d'};
    char ee[] = {'e','s','a','r','e'};
    char er[] = {'r','e','s','a','r','e'};
    int count = 0;
    fgets(imp,sizeof(imp),stdin);
    for (int i = 0; imp[i] != 0; ++i)count++;
    count -= 1;
    char str[count];
    for (int j = 0; j < count; ++j) {
        int index;
        index = count - 1 - j;
        str[j] = imp[index];
    }

    int before;
    before = count;

    do{
        if (count >= 7){
            for (int i = 0; i < 7; ++i){
                int temp;
                temp = i + before - count;
                seven[i] = str[temp];
            }
            if (strncmp(seven,dr,7) == 0){
                count -= 7;
                continue;
            }
        }

        if (count >= 6){
            for (int i = 0; i < 6; ++i){
                int temp;
                temp = i + before - count;
                six[i] = str[temp];
            }
            if (strncmp(six,er,6) == 0){
                count -= 6;
                continue;
            }
        }

        if (count >= 5){
            for (int i = 0; i < 5; ++i){
                int temp;
                temp = i + before - count;
                five[i] = str[temp];
            }
            if (strncmp(five,dm,5) == 0 || strncmp(five,ee,5) == 0){
                count -= 5;
                continue;
            }
        }
        break;
    }while (count > 0);

    if (count == 0){printf("YES");}
    else{printf("NO");}

    return 0;
}
