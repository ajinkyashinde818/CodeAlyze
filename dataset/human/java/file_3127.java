import java.util.Scanner;

public class Main
{

  public static void main(String[] args)
  {
    try (Scanner sc = new Scanner(System.in))
    {
      while (sc.hasNext())
      {
        final int A = sc.nextInt();
        final int B = sc.nextInt();

        int ans = B / A;
        if (B % A != 0)
        {
          ans++;
        }
        System.out.println(ans);
      }
    }

  }
}
