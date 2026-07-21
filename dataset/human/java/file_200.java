import java.util.*;
import java.io.*;
 
public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
  
  public static void main(String[] args) throws Exception {
    int n = Integer.parseInt(br.readLine());
    String[] split = br.readLine().split(" ");
    long[] arr = new long[n];
    
    for(int i = 0; i < n; i++) {
      arr[i] = Long.parseLong(split[i]);
    }
    long sum = 0;
    long min = Long.MAX_VALUE;
    int negs = 0;
    for(long i : arr) {
      if(i < 0)
        negs++;
      long abs = Math.abs(i);
      min = Math.min(min, abs);
      sum += abs;
    }
    if(negs % 2 == 1)
        sum -= min * 2;
    
    pw.println(sum);
    
    pw.close();
  }
}
