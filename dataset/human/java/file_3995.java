/**
 * @author Finn Lidbetter
 */
import java.util.*;
import java.io.*;
import java.awt.geom.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    
    int n = Integer.parseInt(br.readLine());
    int[] order = new int[n];
    int[] val = new int[n];
    int[] bonus = new int[n-1];
    String[] s = br.readLine().split(" ");
    for (int i=0; i<n; i++) {
      order[i] = Integer.parseInt(s[i]);
    }
    s = br.readLine().split(" ");
    for (int i=0; i<n; i++) {
      val[i] = Integer.parseInt(s[i]);
    }
    s = br.readLine().split(" ");
    for (int i=0; i<n-1; i++) {
      bonus[i] = Integer.parseInt(s[i]);
    }
    int prevDish = -1;
    long sum = 0;
    for (int i=0; i<n; i++) {
      int dish = order[i];
      sum += val[dish-1];
      if (prevDish+1==dish) {
        sum += bonus[prevDish-1];
      }
      prevDish = dish;
    }
    System.out.println(sum);
  }
}
