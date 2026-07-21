import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
      Scanner sc = new Scanner(System.in);
      int k = sc.nextInt();
      int s = sc.nextInt();
      sc.close();
      int answer = 0;
      for (int x=0; x<=k; x++) {
        for (int y=0; y<=k; y++) {
          int z = s - x - y;
          if (z >= 0 && z <= k){
            answer++;
          }
        }
      }
      System.out.println(answer);
    }
}
