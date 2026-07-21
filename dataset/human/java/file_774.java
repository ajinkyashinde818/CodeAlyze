import java.util.Scanner;
public class Main
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int R = sc.nextInt();
    int Rating = 0;
    int Result = 0;
    if(K < 10)
    {
      Rating = 100 * (10 - K);
      Result = R + Rating;
      System.out.println(Result);
    }
    else
    {
      System.out.println(R);
    }
  }
}
