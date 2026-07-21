import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String[] str = in.readLine().split(" ");
    if(str[0].charAt(0)<str[1].charAt(0))
      System.out.println("<");
    else if(str[0].charAt(0)>str[1].charAt(0))
      System.out.println(">");
    else
      System.out.println("=");
  }
}
