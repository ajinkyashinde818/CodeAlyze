import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    StringBuilder left = new StringBuilder();
    StringBuilder right = new StringBuilder();
    int q = Integer.parseInt(br.readLine());
    int reverse = 0;
    for (int i = 0; i < q; i++) {
      String[] query = br.readLine().split(" ");
      if ("1".equals(query[0])) {
        reverse = (reverse + 1) % 2;
      } else {
        if (("1".equals(query[1]) && reverse == 0) || ("2".equals(query[1]) && reverse == 1)) {
          left.insert(0, query[2]);
        } else {
          right.append(query[2]);
        }
      }
    }
    br.close();
    String str = left.toString() + s + right.toString();
    if(reverse == 0){
      System.out.println(str);
    } else {
      System.out.println(new StringBuilder(str).reverse().toString());
    }
  }
}
