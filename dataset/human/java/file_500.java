import java.util.*;
public class Main
{
  public static void main(String args[])
  {
    Scanner in=new Scanner(System.in);
    int n,r;
    n=in.nextInt();
    r=in.nextInt();
    if(n>=10)
    {
      System.out.println(r);
      System.exit(0);
    }
    else
    {
      r=r+(100*(10-n));
      System.out.println(r);
    }
  }
}
