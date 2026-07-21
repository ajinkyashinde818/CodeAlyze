#include<stdio.h>
main()
{
    int i=1,x[10000],a=0;
     for(a=0;a<10000;a++)
     {
         scanf("%d",&x[a]);

         if(x[a]==0){
            break;
         }
     }
    for(a=0;a<10000;a++)
    {
        if(x[a]==0)
        {
            break;
        }

        printf("Case %d: %d\n",i,x[a]);
        i++;

    }
    return 0;
}
