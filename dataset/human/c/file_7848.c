/*
  AOJ 0558
  Title:cheese
  @kankichi573
*/
#include <stdio.h>
#include <limits.h>

char xdir[4]={1,0,-1,0};
char ydir[4]={0,1,0,-1};

int H,W,N;
char ban[1000][1001];
int ban2[1000][1001];

short ax[1000000],ay[1000000];
int acnt1,acnt2;




int distance(int xx,int yy)
{
        int i,j,xm,ym,l,flag,xn,yn,acnt3;
        
        //printf("dst=%d %d\n",xx,yy);

        for(i=0;;i++)
        {
                flag=0;
                acnt3=acnt2;
                for(j=acnt1;j<acnt3;j++)
                {
                        //printf("J=%d xy=%d %d:",j,ax[j],ay[j]);
                        xm=ax[j];ym=ay[j];
                        
                        //printf("lyx=%d %d %d\n",i,ym,xm);
                        for(l=0;l<4;l++)
                        {
                                xn=xm+xdir[l];yn=ym+ydir[l];

                                if(xn<0 || xn>=W || yn<0 || yn>=H)
                                        continue;
                                if(yy==yn && xx==xn)
                                {
                                        //printf("MATCHED %d\n",i+1);
                                        return(i+1);
                                }
                                if(ban[yn][xn]!='X' && ban2[yn][xn]==INT_MAX)
                                {
                                        //printf(":lyx=%d %d %d\n",i+1,yn,xn);
                                        ax[acnt2]=xn;
                                        ay[acnt2]=yn;
                                        acnt2++;
                                        ban2[yn][xn]=i+1;
                                        flag=1;
                                }
                        }
                }
                //printf("**\n");
                acnt1=acnt3;                
                if(flag==0)
                        break;
        }
        return(-1);                                
}
void search(char symbol,int * x,int * y)
{
        int i,j;
        //printf("sym=%c\n",symbol);
        for(i=0;i<W;i++)
                for(j=0;j<H;j++)
                        if(ban[j][i]==symbol)
                        {
                                *x=i;*y=j;
                                return;
                        }
        *x=*y=-1;
        return;
}

void clearban2()
{
        int i,j;

        for(i=0;i<1000;i++)
                for(j=0;j<1000;j++)
                        ban2[i][j]=INT_MAX;
}

int get_dist(int from,int to)
{
        int x,y,xx,yy,ret;

        if(from==0)
                search('S',&x,&y);
        else
                search('0'+from,&x,&y);
        //printf("S=%d %d\n",x,y);

        search('0'+to,&xx,&yy);
        //printf("D=%d %d\n",xx,yy);

        acnt1=0;acnt2=1;
        ax[0]=x;ay[0]=y;
        clearban2();
        ban2[y][x]=0;

        //printf("xy=%d %d:",ax[0],ay[0]);

        return(distance(xx,yy));

}
int solve()
{
        int time,ret,i;

        time=0;
        for(i=0;i<N;i++)
        {
                ret = get_dist(i,i+1);
                //printf("%d~%d %d\n",i,i+1,ret);
                time += ret;
        }
        return(time);
}

main()
{
        int i,ret;

        scanf("%d %d %d",&H,&W,&N);
        for(i=0;i<H;i++)
                scanf("%s",&ban[i][0]);

        ret=solve();
        printf("%d\n",ret);



  return(0);
}
