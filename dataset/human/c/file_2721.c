#include <stdio.h>

/* -------- main code -------- */
int    main(void)
{
    int    k, s;
    int    x, y, z;
    int    ptn;
    int    s_ret;

    s_ret = scanf("%d %d", &k, &s);

    ptn = 0;
    for(x = 0; x <= k; x++){
        for(y = 0; y <= k; y++){
            z = s - (x + y);
            if((0 <= z) && (z <= k)){
                ptn++;
            }
        }
    }

    printf("%d\n", ptn);

    return (0);
}
