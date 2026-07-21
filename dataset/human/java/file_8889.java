import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main
{

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    PrintWriter out = new PrintWriter(System.out);

    String s;
    String sl[];

    s = r.readLine();
    sl = s.split(" ");

    int a = Integer.parseInt(sl[0]);
    int b = Integer.parseInt(sl[1]);
    int k = Integer.parseInt(sl[2]);

    int z = a + 1;

    while(k > 0)
    {
      z--;
      if(a % z == 0 && b % z == 0)
      {
        k--;
      }
    }

    out.println(z);
    out.flush();
  }

}
