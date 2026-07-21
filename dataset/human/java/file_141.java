import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);

    String s;
    String sl[];

    s = r.readLine();
    sl = s.split(" ");
    int n = Integer.parseInt(sl[0]);

    long a[] = new long[100004];
    s = r.readLine();
    sl = s.split(" ");

    boolean f = false;
    long m = Long.MAX_VALUE;
    long ss = 0;
    for (int i = 0; i < n; i++)
    {
      if(Long.parseLong(sl[i]) < 0)
      {
        f = !f;
      }
      a[i] = Math.abs(Long.parseLong(sl[i]));
      ss += a[i];
      m = Math.min(m, a[i]);
    }

    System.out.println(ss - (f ? 2 * m : 0));

  }

  public static int gcd(int m, int n)
  {
    if (m < n)
      return gcd(n, m);
    if (n == 0)
      return m;
    return gcd(n, m % n);
  }

}
