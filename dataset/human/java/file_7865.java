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
    long k = Long.parseLong(sl[1]);

    int a[][] = new int[200001][63];

    s = r.readLine();
    sl = s.split(" ");
    for(int i = 1; i <= n; i++)
    {
      a[i][0] = Integer.parseInt(sl[i - 1]);
    }

    for(int i = 1; i < 63; i++)
    {
      for(int j = 1; j <= n; j++)
      {
        a[j][i] = a[a[j][i - 1]][i - 1];
      }
    }

    int v = 1;
    for(int i = 0; i < 63; i++)
    {
      if(((1L << i) & k) > 0)
      {
        v = a[v][i];
      }
    }

    System.out.println(v);

  }

}
