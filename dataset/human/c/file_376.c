#include <stdio.h>

int main()
{
    int contests, displayRating, innerRating = 0;
    
    scanf("%d %d", &contests, &displayRating);
    
    if(contests < 10)
    {   // diplayRating = innerRating - (100 * (10 - contests) with math transformation gives:
        innerRating = displayRating + (100 * (10 - contests));
    }
    else
    {
        innerRating = displayRating;
    }
    
    printf("%d", innerRating);
    
    return 0;
}
