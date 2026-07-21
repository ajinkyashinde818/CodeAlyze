import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String str = in.readLine();
    char[] chr = str.toCharArray();
    Arrays.sort(chr);
    String ary = String.valueOf(chr);
    System.out.println(ary.equals("abc")?"Yes":"No");
  }
}
