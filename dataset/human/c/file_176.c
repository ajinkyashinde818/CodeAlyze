/*
  AOJ 0268
  Title:Kongo Type
  @kankichi573
*/
#include <stdio.h>
#include <float.h>
#include <string.h>


main()
{
        double xx;
        int x,i,j,Q,sign;
        char buf[100];

        scanf("%d",&Q);
        //printf("Q=%d\n",Q);
        for(i=0;i<Q;i++)
        {
                scanf("%x",&x);
                if(x & 1<<31)
                {       sign=-1;
                        x &= 0x7fffffff;
                }
                else
                        sign=1;
                xx=x/128.0;
                if(x & 0x3f)
                {
                        sprintf(buf,"%0.7lf",sign*xx);
                        j=strlen(buf)-1;
                        while(buf[j]=='0')
                                buf[j--]='\0';
                        printf("%s\n",buf);
                }
                else
                        printf("%.1f\n",sign*xx);

        }

        
  return(0);
}
