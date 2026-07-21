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

    int a = Integer.parseInt(sl[0]);
    
    System.out.println((a % 10 == 9 || a / 10 == 9) ? "Yes" : "No");

  }

}
