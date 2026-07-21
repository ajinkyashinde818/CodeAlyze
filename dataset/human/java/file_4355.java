import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args)throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());
    String[] str = in.readLine().split(" ");
    int[] a = new int[n];
    int[] b = new int[n];
    int[] c = new int[n-1];
    int sum = 0;
    
    for(int i=0; i<n; i++) {
      a[i] = Integer.parseInt(str[i]);
    }
    str = in.readLine().split(" ");
    for(int i=0; i<n; i++) {
      b[i] = Integer.parseInt(str[i]);
      sum += b[i];
    }
    str = in.readLine().split(" ");
    for(int i=0; i<n-1; i++) {
      c[i] = Integer.parseInt(str[i]);
    }
    
    for(int i=0; i<n-1; i++) {
        if(a[i]+1==a[i+1]){
          sum += c[a[i]-1];
      }
    }
    
    System.out.println(sum);
  }
}
