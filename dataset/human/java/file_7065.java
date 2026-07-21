import java.util.stream.*;
import java.io.*;

public class Main {
  
  static int n, k;
  static int[] a; 

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String[] in;
    in = br.readLine().split(" ");
    k = Integer.parseInt(in[0]);
    n = Integer.parseInt(in[1]);

    in = br.readLine().split(" ");
    a = Stream.of(in).mapToInt(Integer::parseInt).toArray();

    br.close();

    int maxDistance = a[0] + k - a[n-1];

    for(int i = 0; i < n-1; i++){
      maxDistance = Math.max(maxDistance, a[i+1] - a[i]);
    }
    
    System.out.println(k - maxDistance);
  }
}
