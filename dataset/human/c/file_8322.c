#include <stdio.h>

int main(void){

    char word[20], tipical;
    int wordnum, i, index;

    scanf("%d", &wordnum);
    scanf("%s", &word);
    scanf("%d", &index);

    tipical = word[index-1];

    for(i=0; i<wordnum; i++){
        if(word[i] != tipical){
            word[i] = '*';
        } else {
            continue;
        }
    }

    printf("%s", word);

    return 0;
}
