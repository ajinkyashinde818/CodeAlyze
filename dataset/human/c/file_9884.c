#include<stdio.h>

typedef struct {
  int num;
  int parent_flag;
  int parent;
  int junban;
  int degree_num;
  int depth;
} Root;

int main(){

  int n, i, j, d_num, cnt = 0, temp;

  scanf("%d",&n);

  Root data[100000];
  
  for(i = 0; i < n; i++)
    {
      scanf("%d",&d_num);

      data[d_num].num = d_num;

      scanf("%d",&data[d_num].degree_num);
      
      for(j = 0; j < data[d_num].degree_num; j++)
	{
	  scanf("%d",&temp);
	  
	  data[temp].parent = d_num;
	  data[temp].parent_flag = 1;
	  data[temp].junban = j;
	}

      j = d_num;
      cnt = 0;
      
      while(1)
	{
	  if(data[data[j].parent].parent != -1)
	    {
	      data[d_num].depth = cnt;
	      break;
	    }
	  j = data[j].parent;
	  cnt++;
	}
      
    }

  for(i = 0; i < n; i++)
    {
      if(data[i].parent_flag != 1)
	{
	  data[i].parent = -1;
	  break;
	}
    }

  for(i = 0; i < n; i++)
    {
      j = i;
      cnt = 0;
      
      while(1)
	{
	  if(data[j].parent == -1)
	    {
	      data[i].depth = cnt;
	      break;
	    }
	  j = data[j].parent;
	  cnt++;
	}
    }
      
  for(i = 0; i < n; i++)
    {
      printf("node %d: parent = %d, depth = %d, ", i, data[i].parent, data[i].depth);

      if(data[i].degree_num == 0 && data[i].parent != -1)printf("leaf, [");
      else if(data[i].parent == -1)printf("root, [");
      else printf("internal node, [");

      cnt = 0;
      j = 0;
      
      while(2)
	{
	  if(data[i].degree_num == 0)break;
	  if(data[i].num == data[j].parent && data[j].junban == cnt)
	    {
	      printf("%d",data[j].num);
	      
	      if(cnt == data[i].degree_num - 1)break;
	       
	      printf(", ");
	      cnt++;
	    }
	  j++;
	  if(j == n)j = 0;
	}
      printf("]\n");
    }
  return 0;
}
