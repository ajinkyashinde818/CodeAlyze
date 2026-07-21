#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[10];
    char target;
    int l;
    int target_num;
    scanf("%d", &l);
    scanf("%s",string);
    scanf("%d", &target_num);
    target=string[target_num-1];
    for(int i = 0; i < l; i++)
    {
        if(string[i]!=target)
            string[i]='*';
    }

    printf("%s\n",string);
    
    return 0;
}
