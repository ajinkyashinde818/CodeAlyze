import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {

    new Main().run();
  }

  public void run() {
    
    try(BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {

      String[] lines = in.readLine().split(" ");
      int n = Integer.parseInt(lines[0]);
      int target = Integer.parseInt(lines[1]);

      int[] p = new int[n];
      int[] c = new int[n];
      
      for(int i=0; i<n; i++) {
        lines = in.readLine().split(" ");
        p[i] = Integer.parseInt(lines[0]);
        c[i] = Integer.parseInt(lines[1]);
      }

      int ans = Integer.MAX_VALUE;
      for(int bits=0; bits < (1<<n); bits++){
        int score = 0, cnt = 0, restMax = -1;

        for(int i=0; i<n; i++) {
          if((bits>>i & 1) == 1) {
            score += 100 * (i+1) * p[i] + c[i];
            cnt += p[i];
          }
          else {
            restMax = i;
          }
        }
        // System.out.println(
        //   Integer.toBinaryString(bits) + ":" + score + "," + cnt);

        if(score < target) {
          int point = 100 * (restMax+1);
          int add = (target - score + (point-1)) / point;

          if(add >= p[restMax])
            continue;

          cnt += add;
        }

        ans = Math.min(ans, cnt);
      }

      System.out.println(ans);
    }
    catch(IOException e) {
      System.out.println(e);
    }
  }
}
