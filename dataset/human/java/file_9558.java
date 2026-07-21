import java.util.*;

public class Main{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int cnt=0;
    String ans="No";
    for(int i=0;i<n;i++)
    {
      int x=sc.nextInt();
      int y=sc.nextInt();
      if(x==y)
      {
        cnt++;
        if(cnt==3)
        ans="Yes";
      }
      else
      {
        cnt=0;
      }
    }
    System.out.println(ans);
  }
}
