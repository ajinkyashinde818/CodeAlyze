import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] s = br.readLine().split(" ");
    int a = Integer.parseInt(s[0]);
    int b = Integer.parseInt(s[1]);
    int k = Integer.parseInt(s[2]);
    
    int ans;
    int count = 0;
    for(int i = Math.max(a, b); ; i--){
      if(a % i == 0 && b % i == 0){
        count++;
        if(count == k){
          ans = i;
          break;
        }
      }
    }
    System.out.println(ans);
  }
}
