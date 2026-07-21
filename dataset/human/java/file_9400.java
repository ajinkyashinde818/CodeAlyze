import java.io.*;
import java.util.*;
class Main
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int maxcount = 0;
    int count=0;
    int N = sc.nextInt();
    if(N<3 || N>100)
    {
      System.exit(0);
    }
    int arr[][] = new int[N][2];
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<2; j++)
      {
        arr[i][j]=sc.nextInt();
        if(arr[i][j] < 1 || arr[i][j] > 6)
          System.exit(0);
      }
    }
    for(int i = 0; i < N ; i++)
    {
      if(arr[i][0]==arr[i][1])
      {
        count++;    
      }
      else
      {
        count = 0;
      }
      maxcount = Math.max(maxcount,count);
    }
    if(maxcount>=3)
    {
      System.out.print("Yes");
    }
    else
    {
      System.out.print("No");
    }
  }
}
