/*
AizuOnline A2508
Title King's Inspection
*/
#include <stdio.h>
#include <string.h>
//Global data section
int n;
int k[100];
char s[101];
//
char num2alpha(int x)
{
        if(x<26)
                return('a'+x);
        else
                return('A'+(x-26));
}
main()
{
        int i,len;
        char cn;

        while(EOF!=scanf("%d",&n) && n)
        {
                for(i=0;i<n;i++)  
                        scanf("%d ",&k[i]);
                scanf("%s",s);

                len=strlen(s);
                for(i=0;i<len;i++)
                {
                        if(islower(s[i]))
                                cn = s[i]-'a';
                        else 
                                cn = s[i]-'A'+26;
                        //printf("%d %d:",cn,cn-k[i % n]);
                        printf("%c",num2alpha((52+cn-k[i % n])%52));
                }
                        printf("\n");
        }
        return(0);
}
