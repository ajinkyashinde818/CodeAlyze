#include<stdio.h>

int main(void)
{
  char str1[101],str2[101],temp;
  int i=0,j=0,frag=1,len;
  scanf("%s %s",str1,str2);
  while(frag == 1)
    {
      i=0; frag=0;
      while(str1[i+1] != '\0')
	{
	  if(str1[i] > str1[i+1])
	    {
	      temp = str1[i];
	      str1[i] = str1[i+1];
	      str1[i+1] = temp;
	      frag = 1;
	    }
	  i++;
	}
    }
  frag = 1;
  while(frag == 1)
    {
      j=0; frag = 0;
      while(str2[j+1] != '\0')
	{
	  if(str2[j] < str2[j+1])
	    {
	      temp = str2[j];
	      str2[j] = str2[j+1];
	      str2[j+1] = temp;
	      frag = 1;
	    }
	  j++;
	}
    }
  if(i < j)
    {
      len = i;
      frag = 0;
    }
  else
    {
      len = j;
      frag = 1;
    }
  i=0;
  while(len >= i)
    {
      if(str1[i] < str2[i])
	{
	  printf("Yes\n");
	  return 0;
	}
      else if(str1[i] > str2[i])
	{
	  printf("No\n");
	  return 0;
	}
      i++;
    }
  if(frag == 0)
    {
      printf("Yes\n");
      return 0;
    }
  else
    {
      printf("No\n");
      return 0;
    }
}
