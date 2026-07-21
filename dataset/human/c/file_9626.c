/*
  AOJ 1238
  Title:True Liars
  @kankichi573
  14/10/29 RE
*/
#include <stdio.h>
#include <string.h>

int n,p1,p2,lc;
char relation[600][600];
char devine[600];
int  link[600][3];
int  add_table[600][600];
int search_miketu(char devine[])
{
  int i;
  for(i=1;i<=p1+p2;i++)
    if(devine[i]==0)
      return(i);
  return(0);
}
void count_(char devine[],int *honest,int *liar)
{
  int i;
  *honest=*liar=0;
  for(i=1;i<=p1+p2;i++)
    {
      *honest += ((devine[i]== 1)?1:0);
      *liar   += ((devine[i]==-1)?1:0);
    }
}
void decide(int start,int val,int *hon,int *lia)
{
  int i,r,h,l,h1,l1;
  //printf("decide %d %d\n",start,val);
  h=l=0;
  devine[start]=val;
  for(i=1;i<=p1+p2;i++)
    if((r=relation[start][i]) && devine[i]==0)
      {
	decide(i,r*val,&h1,&l1);
	h += h1;l += l1; 
      }
  if(val==1)
    h++;
  else
    l++;
  *hon=h;*lia=l;
}
void decide2(int start,int val)
{
  int i,r;

  //printf("decide %d %d\n",start,val);
  
  devine[start]=val;
  for(i=1;i<=p1+p2;i++)
    if((r=relation[start][i]) && devine[i]==0)
      {
	decide2(i,r*val);
      }
}
void dump(char devine[])
{
  int i;

  for(i=1;i<=p1+p2;i++)
    printf("%d:",devine[i]);
  printf("\n"); 
}

dump2()
{
  int i;
  for(i=0;i<lc;i++)
    printf("%d: %d %d\n",link[i][0],link[i][1],link[i][2]);
}
dump3()
{
  int i,j,v;
  //for(i=0;i<lc;i++)
  i=lc-1;
    {
      for(j=1;j<=p1+p2;j++)
	if((v=add_table[i][j]))
	  printf("%d[%d]",j,v);
      printf("\n");
    }
}


int solve2()
{
  int mik,hon,lia,i,j,c,s;

  hon=lia=lc=0;
  while((mik=search_miketu(devine)))
    {
      decide(mik,1,&hon,&lia);
      link[lc][0]=mik;
      link[lc][1]=hon;
      link[lc][2]=lia;
      lc++;
    }
  //dump2();
  memset(add_table,0,600*600*sizeof(int));
  
  add_table[0][link[0][1]]=1;
  add_table[0][link[0][2]]=1;
  
  for(i=1;i<lc;i++)
    {
      for(j=1;j<=p1+p2;j++)
	if(c=add_table[i-1][j])
	  {
	    add_table[i][j+link[i][1]] += c;
	    add_table[i][j+link[i][2]] += c;
	  }
    }
  
  //dump3();

  if(add_table[lc-1][p1]!=1 && add_table[lc-1][p2]!=1)
    return(0);
  if(add_table[lc-1][p1]==1)
    {
      s=p1;
      if(p1==p2)
	return(0);
    }

  memset(devine,0,600);
  for(i=lc-1;i>=0;i--)
    {
      //printf("s=%d:",s);
      //printf("l1l2=%d %d\n",link[i][1],link[i][2]);
      if((i==0 && s==link[0][1])||(i>0 &&  add_table[i-1][s-link[i][1]]==1))
	{
	  //printf(":%d o\n",link[i][0]);
	  decide2(link[i][0],1);
	  s-=link[i][1];
	}
      else if((i==0 && s==link[0][2])||(i>0 && add_table[i-1][s-link[i][2]]==1))
	{
	  //printf(":%d x\n",link[i][0]);
	  decide2(link[i][0],-1);
	  s-=link[i][2];
	}
    }
  return(1);
}

void write_devine(char devine[])
{
  int i;
  for(i=1;i<=p1+p2;i++)
    if(devine[i]==1)
      printf("%d\n",i);
  printf("end\n");
	
}
void print_no()
{
  printf("no\n");
}
void print_all()
{
  int i;

  for(i=1;i<=p1+p2;i++)
    printf("%d\n",i);
  printf("end\n");
}
void print_zero()
{
  printf("end\n");
}
main()
{
  int i,x,y,ret,neg,qc;
  char s[4];

  while(scanf("%d %d %d",&n,&p1,&p2) && (n||p1||p2))
    {
      	  memset(relation,0,600*600);
	  memset(devine,0,600);
	  neg=0;qc=0;
	  for(i=0;i<n;i++)
	    {
	      scanf("%d %d %s",&x,&y,s);
	      if(x==y)
		continue;
	      if(s[0]=='y')
		relation[x][y]=relation[y][x]=1;
	      else if(s[0]=='n')
		{
		  relation[x][y]=relation[y][x]=-1;
		  neg=1;
		}
	      devine[x]=devine[y]=0;
	      qc++;
	    }

	  if(qc==0)
	    {
	      if(p2==0)
		print_all();
	      else if(p1==0)
		print_zero();
	      else
		print_no();
	    }
      	  
	  else if(p2==0)
	    {
	      if(neg==0)
		print_all();
	      else
		print_zero();
	    }
	  else if(p1==0)
	    print_zero();
	  else
	    {
	      ret=solve2();
	  
	      if(ret)
		write_devine(devine);
	      else
		print_no();
	    }
	
    }
  return(0);
}
