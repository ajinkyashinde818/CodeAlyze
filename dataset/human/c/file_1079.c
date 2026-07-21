/*
  AOJ 1137
  Title:Numeral System
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
char keta[]="ixcm";
int exp_10(int n)
{
  if(n==0)
    return(1);
  else
    return(10*exp_10(n-1));
}

int mcxi2n(char s[])
{
  char *p;

  int st=1,ret;
  ret=0;st=1;
  for(;*s;s++)
    {
      if(isdigit(*s))
	st=*s-'0';
      else if((p=strchr(keta,*s)))
	{
	  ret+=st*exp_10(p-keta);
	  st=1;
	}
    }
  return(ret);
}
void n2mcxi(char s[],int n)
{
  int i,j;
  char buf[10],c;
  sprintf(buf,"%dm%dc%dx%di",n/1000,(n/100)%10,(n/10)%10,n%10);
  for(i=j=0;buf[i];i++)
    {
      c=buf[i];
      if(c=='1')
	continue;
      if(c=='0')
	{
	  i++;
	  continue;
	}
      s[j++]=c;
    }
  s[j]='\0';
}
main()
{
  int i,ret,na,nb,N;
  char a[10],b[10],c[10];
  
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%s %s",a,b);
      na=mcxi2n(a);
      nb=mcxi2n(b);
      //printf("%d %d\n",na,nb);
      n2mcxi(c,na+nb);
      printf("%s\n",c);
    }
  return(0);
}
