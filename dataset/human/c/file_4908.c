#include<stdio.h>

typedef struct{
  int num;      //割り当て番号
  int par;      //親の番号
  int p_fl;     //親の有無
  int sib;      //兄弟の番号
  int dep;      //深さ
  int deg;      //子供の数
  int deg_n[2]; //子供の数字
  int hei;      //高さ
  int RorL;     //leftなら0、rightなら1
} Nibun;

int main(){

  Nibun data[25];
  int n, i, j, k, cnt, num, degnum, max_dep = 0, h_cnt, temp, flag;
  
  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&num);

      data[num].num = num;
      data[num].deg = 0, data[num].dep = 0;

      scanf("%d",&degnum);
      temp = degnum;

      if(degnum == -1)data[num].hei = 0;
      
      else
	{
	  data[degnum].par = num;
	  data[num].deg++;
	  data[degnum].RorL = 0;
	  data[degnum].p_fl = 1;
	}

      scanf("%d",&degnum);

      if(degnum == -1)data[num].hei = 0;
      else
	{
	  data[degnum].par = num;
	  data[num].deg++;
	  data[degnum].RorL = 1;
	  data[degnum].p_fl = 1;
	}
      data[degnum].sib = temp;
      data[temp].sib = degnum;
    }

  for(i = 0; i < n; i++)  //par = -1となるdata[x]を探す処理
    {
      if(data[i].p_fl != 1)
	{
	  data[i].par = -1;
	  data[i].sib = -1;
	  break;
	}
    }
  
  for(i = 0; i < n; i++)  //depthの処理
    {
      j = i;
      cnt = 0;
      
      while(1)
	{
	  if(data[j].par == -1)
	    {
	      data[i].dep = cnt;
	      if(max_dep < cnt)max_dep = cnt;
	      break;
	    }
	  j = data[j].par;
	  cnt++;
	}
    }
  
  for(i = 0; i < n; i++)  //heightの処理
    {
      data[i].hei = 0 , cnt = 0 , flag = 0;
      if(data[i].deg == 0)continue;

      while(2)
	{
	  for(j = 0; j < n; j++)
	    {
	      if(flag == 1)break;
	      if(data[j].dep == max_dep - cnt)
		{
		  h_cnt = 1;
		  k = j;
		  while(3)
		    {
		      if(data[k].par != data[i].num)
			{
			  if(data[k].par == -1)break;
			  k = data[k].par;
			  h_cnt++;
			}
		      else
			{
			  data[i].hei = h_cnt;
			  flag = 1;
			  break;
			}
		    }
		}
	    }
	  if(flag == 1)break;
	  cnt++;
	}
    }

  for(i = 0; i < n; i++)
    {
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, data[i].par, data[i].sib, data[i].deg, data[i].dep, data[i].hei);

      if(data[i].deg == 0 && data[i].par != -1)printf("leaf\n");
      else if(data[i].par == -1)printf("root\n");
      else printf("internal node\n");
    }
  
  
  
  
  
  
  
  
  return 0;
}
