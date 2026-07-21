import java.util.*;
class Main
{
  public static void main(String args[])
    {
    int N,k=0;
    Scanner sc= new Scanner(System.in);
    N=sc.nextInt();
    int D[][]= new int[N][2];
    for(int i=0;i<N;i++)
      for(int j=0;j<2;j++)
        D[i][j]=sc.nextInt();
    for(int i=0;i<N;i++)
    {
        if(D[i][0]==D[i][1])
        {
          k++;
          if(k==3)
           break;
        }
        else
          k=0;   
      }
    if(k==3)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
