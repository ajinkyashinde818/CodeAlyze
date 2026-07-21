# include <stdio.h>

int main(void)
{
  int K, S;
  scanf("%d%d", &K, &S);
  
  int cnt = 0;
  for (int x = 0; x <= K; ++x)
  {
    for (int y = 0; y <= K; ++y)
    {
      int z = S - x - y;
      
      if (0 <= z && z <= K)
      {
        cnt++;
      }
    }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}
