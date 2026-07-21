//Number 1137

#include <stdio.h>
#include <string.h>
#define MAX 10

int mcxi_to_i(char *array);
void print_by_mcxi(int sum);

int main(void)
{
  int n, i, answer = 0;
  
  scanf("%d", &n);

  for(i=0; i<n; i++)
    {
      char num1[MAX] = {0};
      char num2[MAX] = {0};

      scanf("%s %s", num1, num2);
      
      answer = mcxi_to_i(num1) + mcxi_to_i(num2);

      print_by_mcxi(answer);
    }

  return 0;
}

int mcxi_to_i(char *array)
{
  int j, integer = 0;

  for(j=0; array[j] != '\0'; j++)
    {
      if(array[j] >= '2' && array[j] <= '9')
	{
	  j++;
	  switch(array[j])
	    {
	    case 'm':
	      integer += (array[j-1]-'0')*1000;
	      break;
	    case 'c':
	      integer += (array[j-1]-'0')*100;
	      break;
	    case 'x':
	      integer += (array[j-1]-'0')*10;
	      break;
	    case 'i':
	      integer += (array[j-1]-'0')*1;
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  switch(array[j])
	    {
	    case 'm':
	      integer += 1000;
	      break;
	    case 'c':
	      integer += 100;
	      break;
	    case 'x':
	      integer += 10;
	      break;
	    case 'i':
	      integer += 1;
	      break;
	    default:
	      break;
	    }
	}
    } 
  return integer;
}

void print_by_mcxi(int sum)
{
  int m = 0, c = 0, x = 0, i = 0;

  m = sum / 1000;
  c = (sum - 1000 * m) / 100;
  x = (sum - 1000 * m - 100 * c) / 10;
  i = (sum - 1000 * m - 100 * c - 10 * x);

 
  if(m==1)
    printf("m");
  else if(m>1)
    printf("%dm", m);
  
  if(c==1)
    printf("c");
  else if(c>1)
    printf("%dc", c);
  
  if(x==1)
    printf("x");
  else if(x>1)
    printf("%dx", x);
  
  if(i==1)
    printf("i");
  else if(i>1)
    printf("%di", i);

  printf("\n");
    
}
