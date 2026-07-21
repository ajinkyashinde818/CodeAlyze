import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String[] str = in.readLine().split(" ");
    int a = Integer.parseInt(str[0]);
    int b = Integer.parseInt(str[1]);
    int k = Integer.parseInt(str[2]);
    
    int[] divisor_array = new int[k];
    
    for(int i = Math.min(a,b), j = 0; i>=1; i--) {
      if(a%i==0 && b%i==0){
        divisor_array[j] = i;
        j++;
      }
      if(j == k)
        break;
    }
    System.out.println(divisor_array[k-1]);
  }
}
