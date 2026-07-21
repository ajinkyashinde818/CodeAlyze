/*
AizuOnline A1111
Title Cyber Guardian
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
int n,m;
struct rule_st
{
        char permission;  //permit or deny
        char src[8];
        char dst[8];
} rule[1024];
struct packet_st
{
        char src[8];
        char dst[8];
        int  flag;
        char msg[51];
} packet[1024];

//
int strcmp_wild8(char * s1,char * s2)  //match -1 no 0 s1 pattern s2 packet
{
        int i;
#ifdef DEBUG
        printf("cmp %.8s %.8s\n",s1,s2);
#endif

        for(i=0;i<8;i++)
                if(!((s1[i]=='?' && isdigit(s2[i]))||(s1[i]==s2[i])))
                        return(0);
        return(-1);
}
int is_permit(struct packet_st * pp)
{
        int i;
        for(i=n-1;i>=0;i--)
                if(strcmp_wild8(rule[i].src,pp->src) &&
                   strcmp_wild8(rule[i].dst,pp->dst))
                {
#ifdef DEBUG
                        printf("MATCH %d %c\n",i,rule[i].permission);
#endif
                        if(rule[i].permission=='P')
                                return(-1);
                        else
                                return(0);
                }
        return(0);
}
void print_packet(struct packet_st * pp)
{
        printf("%.8s %.8s %s\n",pp->src,pp->dst,pp->msg);
}
main()
{
        int i;
        char op[10];
        int cnt;
        
        while(EOF!=scanf("%d %d",&n,&m) && (n||m))
        {
                for(i=0;i<n;i++)
                {
                        scanf("%s ",op);

                        if(op[0]=='p')
                                rule[i].permission='P';
                        else
                                rule[i].permission='D';

                        scanf("%s ",rule[i].src);
                        scanf("%s",rule[i].dst);
                }
                for(i=0;i<m;i++)
                {
                        scanf("%s ",packet[i].src);
                        scanf("%s ",packet[i].dst);
                        scanf("%s",packet[i].msg);
                }
                //print();
                cnt=0;
                for(i=0;i<m;i++)
                        if(is_permit(&packet[i]))
                        {
                                cnt++;
                                packet[i].flag=-1;
                        }       
                        else
                                packet[i].flag=0;
                printf("%d\n",cnt);
                for(i=0;i<m;i++)
                        if(packet[i].flag)
                                print_packet(&packet[i]);
        }
return(0);
}
