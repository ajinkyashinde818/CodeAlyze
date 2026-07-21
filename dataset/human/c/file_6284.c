/*
  最大の利益（ある通貨について、時刻 t における価格 Rt (t=0,1,2,,,n−1)が入力とし
  　　　　　　て与えられるので、価格の差 Rj−Ri (ただし、j>i とする) の最大値）
  2018/04/09
*/

#include<stdio.h>

#define MAX 200000

#if 0
int Judge_Max(unsigned int *Rt,int i,int j,int max)
{
  int temp;
  temp = Rt[j] - Rt[i];
  if(temp > max)
    max = temp;

  return max;
}
#endif

int main(void)
{
  int Rt[MAX];
  int i,j;
  int n;/*Rtの数*/
  int max,min;
  /*
    max：Rt[j] - Rt[i]の最大
    min：jより前のRt[j]の最小値
  */

  fscanf(stdin,"%d",&n);
  for(i=0;i<n;i++)
    fscanf(stdin,"%d",&Rt[i]);

  min = Rt[0];
  for(j=1;j<n;j++){
    if((Rt[j] - min) > max || j == 1)
      max = Rt[j] - min;
    if(Rt[j] < min)
      min = Rt[j];
  }
  printf("%d\n",max);
  
  return 0;
}
