/*
  AOJ 2090
  Title:Repeated Subsequences
  @kankichi573
  14/11/7 TLE
*/
#include <stdio.h>
#include <string.h>
#define max(x,y) (((x)>(y))?(x):(y))

short lcs[300][300];

void  output_lcs(char *in1,char *in2,short lcs[300][300],
		int y,int x,char *out)
{
  *out='\0';
  if(y==0 || x==0)
    return;

  //printf("[%d,%d]:%c %c\n",y,x,in1[y],in2[x]);

  if(in1[y-1]==in2[x-1])
    {
      //printf("%c",in1[y-1]);
      *out=in1[y-1];
      out++;
      *out='\0';
      output_lcs(in1,in2,lcs,y-1,x-1,out);
    }
  else
    {
      if(lcs[y-1][x] >= lcs[y][x-1])
	output_lcs(in1,in2,lcs,y-1,x,out);
      else
	output_lcs(in1,in2,lcs,y,x-1,out);
    }

}
void dump_lcs(int len1,int len2,short lcs[300][300])
{
  int i,j;
  for(i=0;i<=len1;i++)
    {
      for(j=0;j<=len2;j++)
	printf("%-2d|",lcs[i][j]);
      printf("\n");
    }
}


int longest_common_subseq(char *in1,int len1,char *in2,int len2,char *out)
{
  int i,j;
  char *p;

  for(i=0;i<len1;i++)
    lcs[i][0]=0;
  for(i=0;i<len2;i++)
    lcs[0][i]=0;
  for(i=0;i<len1;i++)
    for(j=0;j<len2;j++)
      if(in1[i]==in2[j])
	lcs[i+1][j+1]=lcs[i][j]+1;
      else
	lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
  
  //dump_lcs(len1,len2,lcs);
  output_lcs(in1,in2,lcs,len1,len2,out);
  return(lcs[len1][len2]);
}

void print_result(char *in1,int len1,char *in2,int len2,char *out)
{
  int i;
  for(i=0;i<len1;i++)
    printf("%c",in1[i]);
  printf(" ");
  for(i=0;i<len2;i++)
    printf("%c",in2[i]);
  printf("|");
  printf("%s\n",out);
}
reverse_print(char *r,int len)
{
  int i;
  for(i=len-1;i>=0;i--)
    printf("%c",r[i]);
  printf("\n");
}
main()
{
  char in1[301],in2[301],out[151],result[151];
  int len,len2,max_,i;
#ifdef TEST  
  scanf("%s %s",in1,in2);
  longest_common_subseq(in1,strlen(in1),in2,strlen(in2),out);
  printf("ANS:%s[%d]\n",out,strlen(out));
#else
  while(scanf("%s",in1) && 0!=strcmp("#END",in1))
    {
      *result='\0';
      len=strlen(in1);
      max_=0;
      for(i=max(max_,1);i<len;i++)
	  {
	    len2=longest_common_subseq(in1,i,in1+i,len-i,out);
	    if(max_<len2)
	      {
		max_=len2;
		strcpy(result,out);
	      }
#ifdef DEBUG
	    print_result(in1,i,in1+i,len-i,out);
#endif
	  }
      reverse_print(result,max_);
    }
 #endif
  return(0);
}
