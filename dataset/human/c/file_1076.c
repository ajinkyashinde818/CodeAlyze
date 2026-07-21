/* 
   AOJ 1137
   Numeral System
   2015/5/21
*/

#include<stdio.h>

char output_str[10] = {'\0'};

int mcxi_num(char *input_str)
{
  int i, base, num, sum = 0;
 
  for(i = 0; input_str[i] != '\0'; i++)
    {
      if(input_str[i] > 60)
	{
	  switch(input_str[i])
	    {
	    case 'm':
	      sum += 1000;
	      break;
	    case 'c':
	      sum += 100;
	      break;
	    case 'x':
	      sum += 10;
	      break;
	    case 'i':
	      sum += 1;
	      break;
	    }
	}
      else
	{
	  num = input_str[i] - '0';

	  switch(input_str[++i])
	    {
	    case 'm':
	      base = 1000;
	      break;
	    case 'c':
	      base = 100;
	      break;
	    case 'x':
	      base = 10;
	      break;
	    case 'i':
	      base = 1;
	      break;
	    }
	  sum += num * base;
	}
    }

  return sum;
}

void num_mcxi(int num)
{
  int i = 0, j, div, rest = num;
  char inp_ch;
  for(j = 1000; j > 0; j = j / 10)
    {
      div = rest / j;
      rest = rest % j;
      if(div == 0)
	{
	  continue;
	}
      else if(div == 1)
	{
	  switch(j)
	    {
	    case 1000:
	      output_str[i++] = 'm';
	      break;
	    case 100:
	      output_str[i++] = 'c';
	      break;
	    case 10:
	      output_str[i++] = 'x';
	      break;
	    case 1:
	      output_str[i++] = 'i';
	      break;
	    }
	}
      else
	{
	  switch(j)
	    {
	    case 1000:
	      output_str[i++] = div + '0';
	      output_str[i++] = 'm';
	      break;
	    case 100:
	      output_str[i++] = div + '0';
	      output_str[i++] = 'c';
	      break;
	    case 10:
	      output_str[i++] = div + '0';
	      output_str[i++] = 'x';
	      break;
	    case 1:
	      output_str[i++] = div + '0';
	      output_str[i++] = 'i';
	      break;
	    }
	}
    }
  output_str[i] = '\0';

}

int main(void)
{
  int num, i, sum = 0;
  char first[10], second[10];

  scanf("%d", &num);

  for(i = 0; i < num; i++)
    {
      scanf("%s %s", first, second);
      //     scanf("%d", &sum);
      //      num_mcxi(sum);
      
      //    printf("%d\n", mcxi_num(first) + mcxi_num(second));
      num_mcxi(mcxi_num(first) + mcxi_num(second));
      printf("%s\n", output_str);
    }

  return 0;
}
