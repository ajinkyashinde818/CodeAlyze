import java.io.*;
import java.math.BigDecimal;
import java.util.Objects;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int n = Integer.parseInt(br.readLine());
    int[] an = new int[n];
    String[] data = br.readLine().split(" ");
    
    for (int i=0; i<n; i++){
      an[i] = Integer.parseInt(data[i]);
    }
    BigDecimal temp = new BigDecimal(0);
    BigDecimal sum = new BigDecimal(0);
    for (int i=0; i<n; i++){
      sum = sum.add(new BigDecimal(an[i]));
    }
    BigDecimal min = null;
    BigDecimal temp2;
    for (int i=0; i<n-1; i++){
      temp = temp.add(new BigDecimal(an[i]));
      temp2 = sum.subtract(temp.multiply(new BigDecimal(2))).abs();
      if (min == null){
        min = temp2;
      }
      if (min.compareTo(temp2)>0){
        min = temp2;
      }
    }
    System.out.println(Objects.requireNonNull(min).toPlainString());
  }
}
