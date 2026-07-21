#include <iostream>
#include <stdio.h>

#define NUM_MAX 9

char str[] = { '#', '.' };

int main(int argc, const char * argv[]) {
    
    int H, W;
    
    while(1)
    {
        scanf("%d%d", &H, &W);
        
        if(H == 0 && W == 0) break;
        
        for(int y = 0; y < H; ++y)
        {
            for(int x = 0; x < W; ++x)
            {
                printf("%c", str[(x + y) % 2]);
            }
            puts("");
        }
        
        
        puts("");
        
    }
    
    
    return 0;
}
