import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String n = in.readLine();
    System.out.println(n.substring(0,1).equals("9") || n.substring(1,2).equals("9")?
                       "Yes":"No");
  }
}
