/* 
   AOJ 2508
   King's Inspection
   2015/7/25
*/
#include<stdio.h>


#define K_MAX 100
#define L_MAX 200
#define LARGE_MIN 65
#define LARGE_MAX 90
#define SMALL_MIN 97
#define SMALL_MAX 122
#define ALPHABET_RANGE 26

void ans_f(int* key, int key_num, int* list, int list_num, char* out_str)
{
  int i, new_char, key_val, j;

  for(i = 0; i <= list_num; i++)
    {
      /* printf("\n"); */
      /* printf("%c", list[i]); */
      key_val = key[i % key_num];
      new_char = list[i] - key_val;
      if(list[i] <= LARGE_MAX)
	{
	  //	  printf("hoge");
	  if(LARGE_MIN <= new_char)
	    {
	      list[i] = new_char;
	      //	      printf("0");
	    }
	  else
	    {
	      if(LARGE_MIN - ALPHABET_RANGE <= new_char)
		{
		  list[i] = SMALL_MAX - (LARGE_MIN - new_char) + 1;
		  //  printf("1");
		}
	      else
		{
		  list[i] = ALPHABET_RANGE * 2 - key_val + list[i];
		  //		  printf("2");
		}
	    }
	}
      else
	{
	  if(SMALL_MIN <= new_char)
	    {
	      list[i] = new_char;
	      //	      printf("3");
	    }
	  else
	    {
	      if(LARGE_MIN + 6 <= new_char && LARGE_MAX + 6)
		{
		  list[i] = new_char - 6;
		  //  printf("4");
		}
	      else
		{
		  list[i] = ALPHABET_RANGE * 2 - key_val + list[i];
		  //		  printf("5");
		}
	    }
	}
    }
  for(j = 0; j < i; j++)
    {
      out_str[j] = (char)list[j];
    }
  out_str[j] = '\n';
  out_str[j + 1] = '\0';
}

int main(void)
{
  int key_num, i, number = 0;
  int key[K_MAX], list[L_MAX];
  char input_char, ans_str[L_MAX], dast;
  while(1)
    {
      for(i = 0; i < K_MAX; i++)
	{
	  key[i] = 0;
	}
      for(i = 0; i < L_MAX; i++)
	{
	  list[i] = 0;
	}

      scanf("%d", &key_num);

      if(key_num == 0)
	{
	  break;
	}

      for(i = 0; i < key_num; i++)
	{
	  scanf("%d", &key[i]);
	}

      scanf("%c", &dast);
      //      scanf("%c", &dast);
      for(i = 0; ; i++)
	{
	  //	  printf("fuga");
	  scanf("%c", &input_char);
	  if(input_char == '\n')
	    {
	      break;
	    }
	  list[i] = (int)input_char;
	}
      //      printf("foo");
      ans_f(key, key_num, list, i - 1, ans_str);
 
      printf("%s", ans_str);

    }
  return 0;
}
